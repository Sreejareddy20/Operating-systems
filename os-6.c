#include <stdio.h>

struct Process {
    int id;
    int priority;
    int burst_time;
    int remaining_time;
    int arrival_time;
};

void PreemptivePriorityScheduling(struct Process processes[], int n) {
    int total_time = 0;
    int completed = 0;
    printf("Time\tProcess\n");
    int i;

    while (completed < n) {
        int highest_priority = -1;
        int highest_priority_index = -1;

        for (i=0;i<n;i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority > highest_priority && processes[i].arrival_time <= total_time) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }

        if (highest_priority_index == -1) {
            total_time++;
        } else {
            processes[highest_priority_index].remaining_time--;
            total_time++;

            if (processes[highest_priority_index].remaining_time == 0) {
                completed++;
                printf("%d\tP%d\n", total_time, processes[highest_priority_index].id);
            }
        }
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
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    PreemptivePriorityScheduling(processes, n);

    return 0;
}
