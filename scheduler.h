#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
using namespace std;

struct Process {
    string pid;
    int arrival;
    int burst;
    int remaining;
    int priority;

    int start = -1;
    int completion = 0;
};

void run_fcfs(vector<Process> processes);
void run_sjf(vector<Process> processes);
void run_srtf(vector<Process> processes);
void run_rr(vector<Process> processes, int quantum);
void run_priority(vector<Process> processes);

#endif
