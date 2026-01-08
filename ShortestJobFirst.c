#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Scheduler.h"


void shortestJobFirst(Process *jobs, int n)
{
    int time =0;
    int start_time;
    for(int i=0; i<n; i++)
    {
        if(time < jobs[i].arrival_time) time = jobs[i].arrival_time;
        
        start_time= time;
        time += jobs[i].burst_time;
        jobs[i].completion_time = time;
        jobs[i].turnaround_time = jobs[i].completion_time - jobs[i].arrival_time;
        jobs[i].waiting_time = jobs[i].turnaround_time - jobs[i].burst_time;
        jobs[i].response_time = start_time - jobs[i].arrival_time;
    }
}


int cmp_burst_time(const void *a, const void *b) {
    Process *j1 = (Process *)a;
    Process *j2 = (Process *)b;
    return j1->burst_time - j2->burst_time;
}

