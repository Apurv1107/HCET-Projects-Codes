#include <stdio.h>

struct Process {
    int pid, bt, at;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int wt[n], tat[n], i, j;

    for(i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &p[i].at);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &p[i].bt);
    }

    // Sort by Burst Time (simple selection sort)
    for(i = 0; i < n - 1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[j].bt < p[i].bt) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + p[i-1].bt;

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + p[i].bt;

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, wt[i], tat[i]);

    return 0;
}
