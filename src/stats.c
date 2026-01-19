#include "../include/stats.h"
#include <stdio.h>

void print_process_table(Process *p, int n) {
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].start_time,
            p[i].completion_time,
            p[i].turnaround_time,
            p[i].waiting_time,
            p[i].response_time
        );
    }
}

void print_average_times(Process *p, int n) {
    double avg_wt = 0, avg_tat = 0, avg_rt = 0;

    for (int i = 0; i < n; i++) {
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
        avg_rt += p[i].response_time;
    }

    printf("\nAverage Waiting Time     : %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time  : %.2f", avg_tat / n);
    printf("\nAverage Response Time    : %.2f\n", avg_rt / n);
}
