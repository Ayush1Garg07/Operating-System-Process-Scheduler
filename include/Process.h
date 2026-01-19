#ifndef PROCESS_H
#define PROCESS_H

#include <stdbool.h>

typedef struct{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;

    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int response_time;

    int priority;
    int tickets;
    int queue_level;

    bool is_completed;
}Process;

#endif