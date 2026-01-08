#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "Queue.h"
#include "Process.h"

#define MAX 100

int min(int a, int b)
{
    if(a<b) return a;
    else return b;
}


void MultiLevelFeedbackQueue(Process *jobs, int k)
{
    Queue q1,q2,q3;
    initQueue(&q1);
    initQueue(&q2);
    initQueue(&q3);

    int time=0;
    int quantum[3] = {4,8,1000};
    int completed=0;

    while(completed < k){
        for(int i=0; i<k; i++)
        {
            if(jobs[i].arrival_time == time)
            {
                enqueue(&q1, i);
                jobs[i].queue_level = 0;
            }
        }

        int idx = -1, level=-1;
        if(!isEmpty(&q1)){
            idx = dequeue(&q1);
            level=0;
        }
        else if(!isEmpty(&q2)){
            idx = dequeue(&q2);
            level = 1;
        }
        else if(!isEmpty(&q3)){
            idx = dequeue(&q3);
            level = 2;
        }
        else{
            time++;
            continue;
        }

        Process *p = &jobs[idx];
        int runtime = min(p->remaining_time, quantum[level]);
        
        if(p->start_time == -1){
            p->start_time = time;
            p->response_time = time - p->arrival_time;
        }

        for(int i=0; i<runtime ; i++)
        {
            time++;
            for(int j=0; j < k; j++)
            {
                if(jobs[j].arrival_time == time)
                {
                    enqueue(&q1, j);
                    jobs[j].queue_level=0;
                }
            }
        }

        p->remaining_time -= runtime; 

        if(p->remaining_time == 0){
            p->completion_time = time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            p->is_completed = true;
            completed++;
        }
        else{
            if(level == 0) enqueue(&q1, idx);
            else enqueue (&q2, idx);
        }

    }
}



