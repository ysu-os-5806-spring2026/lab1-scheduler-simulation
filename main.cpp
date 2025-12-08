#include <iostream>
#include <vector>
#include "scheduler.h"
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid
            >> processes[i].arrival
            >> processes[i].burst
            >> processes[i].priority;
        processes[i].remaining = processes[i].burst;
    }

    run_fcfs(processes);
    run_sjf(processes);
    run_srtf(processes);
    run_rr(processes, 2);
    run_priority(processes);

    return 0;
}
