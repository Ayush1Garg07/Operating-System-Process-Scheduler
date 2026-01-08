#include <stdio.h>
#include <limits.h>
#include "Queue.h"
#include "Process.h"

#define MAX 100



void Round_Robin(Process *jobs, int k)
{
    Queue q;
    initQueue(&q);

    int time = 0;
    int completed =0;
    int quantum=2; //we assumed it as 2, it can be anything
    int remaining_time[k], visited[k];

    for(int i=0; i<k; i++)
    {
        remaining_time[i] = jobs[i].burst_time;
        visited[i]=0;
    }

    for(int i=0; i<k; i++)
    {
        if(jobs[i].arrival_time <= time && !visited[i]){
            enqueue(&q, i);
            visited[i]=1;
        }
    }

    while(completed < k)
    {
        if(isEmpty(&q)){
            time++;            //CPU idle

            for(int i=0; i<k; i++)
            {
                if(jobs[i].arrival_time <= time && !visited[i])
                {
                    remaining_time[i] = jobs[i].burst_time;
                    visited[i] =1;
                }
            }
            continue;    
        }

        int idx = dequeue(&q);

        if(remaining_time[idx] == jobs[idx].burst_time)
        {
            jobs[idx].response_time = time - jobs[idx].arrival_time;
        }



        int exec_time = (remaining_time[idx] < quantum) ? remaining_time[idx] : quantum;
        time+=exec_time;
        remaining_time[idx] -= exec_time;
        
        for(int i=0; i<k; i++)
        {
            if(jobs[i].arrival_time <= time && !visited[i])
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }

        if(remaining_time[idx] > 0){
            enqueue(&q, idx);
        }
        else{
            completed++;
            jobs[idx].completion_time = time;
            jobs[idx].turnaround_time = jobs[idx].completion_time - jobs[idx].arrival_time;
            jobs[idx].waiting_time = jobs[idx].turnaround_time - jobs[idx].burst_time;
        }

    }           
}
