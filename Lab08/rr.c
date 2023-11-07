#include <stdio.h>

int main(){

    int i, n, remain, flag = 0;
    int t, tq, at[10], bt[10], rt[10];
    float AVGwt = 0, AVGtat = 0;
    printf("Enter the no Process & Time Quantum : \t ");
    scanf("%d%d", &n, &tq);
    remain = n;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival and Burst Time P[%d]:", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\n\nProcess\t|Completion Time| Turnaround Time|Waiting Time\n\n");
    for (t = 0, i = 0; remain != 0;)
    {
        if (rt[i] <= tq && rt[i] > 0)
        {
            t += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            rt[i] -= tq;
            t += tq;
        }
        if (rt[i] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t|%d\t|\t%d\t|\t%d\n", i + 1, t, t - at[i], t - at[i] - bt[i]);
            AVGwt += t - at[i] - bt[i];
            AVGtat += t - at[i];
            flag = 0;
        }

        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= t)
            i++;
        else
            i = 0;
    }
    printf("\nAverage Waiting Time= %f\n", AVGwt * 1.0 / n);
    printf("Avg Turnaround Time = %f", AVGtat * 1.0 / n);
    return 0;
}
