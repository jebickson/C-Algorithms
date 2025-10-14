#include <stdio.h>
#include <conio.h>

struct process { // process structure
    int pid, bt, wt, tt; // process id, burst time, waiting time, turnaround time
} p[10]; // process array[10]

void main() { // main function
    int i, n, totwt = 0, tottt = 0; // total waiting time and total turnaround time
    float avgwt, avgtt; // average waiting time and average turnaround time
    clrscr(); // clear screen
 
    printf("Enter number of processes: "); // take number of processes as input
    scanf("%d", &n); // store input in n

    for(i = 0; i < n; i++) { // loop to take burst time input for each process
        p[i].pid = i + 1; // process id
        printf("Enter burst time of process P%d: ", p[i].pid); // prompt for burst time
        scanf("%d", &p[i].bt); // store burst time in process array
    }

    p[0].wt = 0; // waiting time for first process is 0
    p[0].tt = p[0].bt; // turnaround time for first process is its burst time

    for(i = 1; i < n; i++) { // calculate waiting time and turnaround time for each process
        p[i].wt = p[i - 1].wt + p[i - 1].bt; // waiting time is sum of previous waiting time and burst time
        p[i].tt = p[i].wt + p[i].bt; // turnaround time is waiting time plus burst time
    }

    printf("\nPID\tBT\tWT\tTT\n"); // print table header
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt); // print process id, burst time, waiting time, turnaround time
        totwt += p[i].wt; // accumulate total waiting time
        tottt += p[i].tt; // accumulate total turnaround time
    }

    avgwt = (float)totwt / n; // calculate averages
    avgtt = (float)tottt / n; // calculate averages

    printf("\nAverage Waiting Time: %.2f", avgwt); // print average waiting time
    printf("\nAverage Turnaround Time: %.2f", avgtt); // print average turnaround time

    getch();
}
