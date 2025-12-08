#include "scheduler.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void print_stats(const string& name,
                 const vector<Process>& procs,
                 const vector<string>& order,
                 const vector<int>& wait,
                 const vector<int>& turn)
{
    cout << "=== " << name << " ===\n";
    cout << "Order: ";
    for (auto& p : order) cout << p << " ";
    cout << "\n";

    cout << "Wait Times: ";
    for (int i = 0; i < procs.size(); i++)
        cout << procs[i].pid << ":" << wait[i] << " ";
    cout << "\n";

    cout << "Turnaround Times: ";
    for (int i = 0; i < procs.size(); i++)
        cout << procs[i].pid << ":" << turn[i] << " ";
    cout << "\n\n";
}

void run_fcfs(vector<Process> processes)
{
    int time = 0;
    vector<string> order;
    vector<int> wait(processes.size());
    vector<int> turn(processes.size());

    sort(processes.begin(), processes.end(),
         [](auto& a, auto& b){ return a.arrival < b.arrival; });

    for (int i = 0; i < processes.size(); i++) {
        if (time < processes[i].arrival)
            time = processes[i].arrival;

        wait[i] = time - processes[i].arrival;
        time += processes[i].burst;
        turn[i] = time - processes[i].arrival;

        order.push_back(processes[i].pid);
    }

    print_stats("FCFS", processes, order, wait, turn);
}

void run_sjf(vector<Process> processes) {
    // TODO: Students implement
}

void run_srtf(vector<Process> processes) {
    // TODO
}

void run_rr(vector<Process> processes, int q) {
    // TODO
}

void run_priority(vector<Process> processes) {
    // TODO
}
