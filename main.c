#include <stdio.h>
#include "Scheduler.h"

int main() {
    int n, choice, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i;
        printf("AT BT: ");
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].start_time = -1;
        p[i].is_completed = false;
    }

    printf("1.FCFS 2.SJF 3.SRTF 4.RR 5.MLFQ 6.Lottery\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: FCFS(p, n); break;
        case 2: shortestJobFirst(p, n); break;
        case 3: ShortestRemainingtimefirst(p, n); break;
        case 4:
            printf("Quantum: ");
            scanf("%d", &quantum);
            Round_Robin(p, n, quantum);
            break;
        case 5: MLFQ(p, n); break;
        case 6: LotteryScheduling(p, n); break;
    }

    return 0;
}
