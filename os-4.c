#include <stdio.h>

struct Process {
    int id;
    int burst_time;
};

void SJN(struct Process processes[], int n) {
    int total_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int i;
    int j;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i=0;i<n;i++) {
        int min_time = processes[i].burst_time;
        int min_index = i;

        for (j=i;j<n;j++) {
            if (processes[j].burst_time < min_time) {
                min_time = processes[j].burst_time;
                min_index = j;
            }
        }

        struct Process temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;

        waiting_time += total_time;
        turnaround_time += total_time + processes[i].burst_time;

        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, waiting_time, turnaround_time);

        total_time += processes[i].burst_time;
    }
}

int main() {
    int n;
    int i;
    int j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (i=0;i<n;i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    SJN(processes, n);

    return 0;
}
