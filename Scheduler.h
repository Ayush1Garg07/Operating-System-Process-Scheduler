#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void FCFS(Process *p, int n);
void shortestJobFirst(Process *p, int n);
void ShortestRemainingtimefirst(Process *p, int n);
void Round_Robin(Process *p, int n, int k);
void MultiLevelFeedbackQueue(Process *p, int n);
void LotteryScheduling(Process *p, int n);


#endif
