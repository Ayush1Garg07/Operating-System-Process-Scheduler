#include "Scheduler.h"
#include <stdlib.h>
#include <limits.h>

void ShortestRemainingtimefirst(Process *jobs, int n)
{
    int time=0;
    int completed=0;

    while(completed < n)
    {
        int idx = -1;
        int min_remain_time = INT_MAX;

        for(int i=0; i<n ;i++)
        {
            if(jobs[i].arrival_time <= time && jobs[i].remaining_time > 0)
            {
                if(jobs[i].remaining_time < min_remain_time)
                {
                    min_remain_time = jobs[i].remaining_time;
                    idx = i;
                }
            }
        }

        if(idx != -1)
            {
                if(jobs[idx].start_time == -1)
                    jobs[idx].start_time = time;


                    jobs[idx].remaining_time -=1;
                    time+=1;

                if (jobs[idx].remaining_time == 0) {
                jobs[idx].completion_time = time;
                jobs[idx].turnaround_time = jobs[idx].completion_time - jobs[idx].arrival_time;
                jobs[idx].waiting_time = jobs[idx].turnaround_time - jobs[idx].burst_time;
                jobs[idx].response_time = jobs[idx].start_time - jobs[idx].arrival_time;
                completed++;
            }
            }
            else {
                time += 1;
            }
    }
}