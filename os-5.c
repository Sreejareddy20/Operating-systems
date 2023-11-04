#include<stdio.h>

struct Process {
    int id;
    int priority;
};

void PriorityScheduling(struct Process processes[], int n) {
    int total_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int i;
    int j;
    printf("Process\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i=0;i<n;i++) {
        int highest_priority = processes[i].priority;
        int highest_priority_index = i;

        for (j=i;j<n;j++) {
            if (processes[j].priority > highest_priority) {
                highest_priority = processes[j].priority;
                highest_priority_index = j;
            }
        }

        struct Process temp = processes[i];
        processes[i] = processes[highest_priority_index];
        processes[highest_priority_index] = temp;

        waiting_time += total_time;
        turnaround_time += total_time + 1;

        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority, waiting_time, turnaround_time);

        total_time++;
    }
}

int main() {
    int n;
    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (i=0;i<n;i++) {
        processes[i].id = i + 1;
        printf("Enter priority for process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    PriorityScheduling(processes, n);

    return 0;
}

