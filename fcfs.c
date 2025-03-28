#include <stdio.h>

int main() {
    int pid[15], bt[15], n, ct[15], wt[15], total_wt = 0;
    float avg_wt;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for (int i = 0; i < n; i++) scanf("%d", &pid[i]);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    ct[0] = 0;
    for (int i = 0; i < n; i++) {
        ct[i + 1] = ct[i] + bt[i];  
        wt[i] = ct[i + 1] - bt[i];  
        total_wt += wt[i];
    }

    printf("|  Process ID  |  Burst Time  |  Completion Time  |  Waiting Time  |\n");
    printf("|-------------|-------------|----------------|-------------|\n");
    for (int i = 0; i < n; i++) 
        printf("|%12d |%12d |%16d |%12d |\n", pid[i], bt[i], ct[i + 1], wt[i]);

    avg_wt = (float)total_wt / n;
    printf("Average Waiting Time: %.2fms\n", avg_wt);

    return 0;
}
