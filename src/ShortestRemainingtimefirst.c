#include "Scheduler.h"
#include <stdlib.h>
#include <limits.h>

void ShortestRemainingtimefirst(Process *jobs, int n)
{
    int time = 0, completed = 0;

    while (completed < n)
    {
        int idx = -1;
        int min_remain = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (jobs[i].arrival_time <= time && jobs[i].remaining_time > 0)
            {
                if (jobs[i].remaining_time < min_remain ||
                   (jobs[i].remaining_time == min_remain &&
                    jobs[i].arrival_time < jobs[idx].arrival_time))
                {
                    min_remain = jobs[i].remaining_time;
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            if (jobs[idx].start_time == -1)
                jobs[idx].start_time = time;

            jobs[idx].remaining_time--;
            time++;

            if (jobs[idx].remaining_time == 0)
            {
                jobs[idx].completion_time = time;
                jobs[idx].turnaround_time = time - jobs[idx].arrival_time;
                jobs[idx].waiting_time =
                    jobs[idx].turnaround_time - jobs[idx].burst_time;
                jobs[idx].response_time =
                    jobs[idx].start_time - jobs[idx].arrival_time;
                completed++;
            }
        }
        else
        {
            time++;
        }
    }
}
