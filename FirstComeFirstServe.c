#include "Scheduler.h"
#include <string.h>

void FCFS(Process *jobs,int n)
{
    int time=0;
    int start_time;
    for(int i=0; i<n; i++)
    {
        if(time < jobs[i].arrival_time) 
        time = jobs[i].arrival_time;
        
        start_time = time;
        time += jobs[i].burst_time;
        jobs[i].completion_time = time;
        jobs[i].turnaround_time = jobs[i].completion_time - jobs[i].arrival_time;
        jobs[i].waiting_time = jobs[i].turnaround_time - jobs[i].burst_time;
        jobs[i].response_time = start_time - jobs[i].arrival_time;

    }
}

