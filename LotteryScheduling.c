#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "Scheduler.h"

void LotteryScheduling(Process *jobs, int n)
{
    int total_tickets, time_elapse=0, completed=0;

    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        jobs[i].remaining_time = jobs[i].burst_time;
        jobs[i].turnaround_time=0;
        jobs[i].waiting_time=0;
        jobs[i].is_completed=0;
        jobs[i].response_time=-1;
    }

    while(completed<n)
    {
       total_tickets=0;
       for(int i=0; i<n; i++){
            if (!jobs[i].is_completed)             //Calculate the total tickets
            {
                total_tickets += jobs[i].tickets;
            }
       } 

       if(total_tickets==0) break;
       
       int winticket = rand()%total_tickets + 1;   //Random Selection of Winning Ticket

       int count=0;
       for(int i=0; i<n; i++)
       {
           if(jobs[i].is_completed) continue;
           count+=jobs[i].tickets;

           if(winticket<=count){                //Checking in which range winning ticket lies

            if (jobs[i].response_time == -1)
            jobs[i].response_time = time_elapse;

            jobs[i].remaining_time--;
            time_elapse++;

            if(jobs[i].remaining_time==0){
                jobs[i].is_completed=1;
                completed++;
                jobs[i].turnaround_time = time_elapse;
                jobs[i].waiting_time = jobs[i].turnaround_time - jobs[i].burst_time;
            }
            break;
           }
       }
    }
}

