#include <stdio.h>
#include <conio.h>

struct process {
    int pid, bt, rt, wt, tt; // process id, burst time, remaining time, waiting time, turnaround time
} p[10]; // process array[10] 

void main() { // main function
    int n, i, time = 0, tq, done; // number of processes, loop variable, current time, time quantum, remaining processes, done flag
    float totwt = 0, tottt = 0; // total waiting time and total turnaround time
    clrscr();

    printf("Enter number of processes: "); // take number of processes as input
    scanf("%d", &n); // store input in n

    for(i = 0; i < n; i++) { // loop to take burst time input for each process
        p[i].pid = i + 1; // process id starts from 1
        printf("Enter burst time for P%d: ", p[i].pid); // prompt for burst time
        scanf("%d", &p[i].bt); // store burst time in process array
        p[i].rt = p[i].bt; // remaining time is initially equal to burst time
    }

    printf("Enter Time Quantum: "); // take time quantum as input
    scanf("%d", &tq); // store input in tq

    do { // loop until all processes are done
        done = 1; // assume all processes are done
        for(i = 0; i < n; i++) { // loop through each process
            if(p[i].rt > 0) { // if remaining time is greater than 0
                done = 0; // not done yet

                if(p[i].rt > tq) { // if remaining time is greater than time quantum
                    time += tq; // increment current time by time quantum
                    p[i].rt -= tq; // decrement remaining time by time quantum
                } else { // if remaining time is less than or equal to time quantum
                    time += p[i].rt; // increment current time by remaining time
                    p[i].wt = time - p[i].bt; // calculate waiting time
                    p[i].rt = 0; // remaining time is now 0
                    p[i].tt = time; // turnaround time is current time
                }
            }
        }
    } while(!done); // repeat until all processes are done

    printf("\nPID\tBT\tWT\tTT"); // print table header
    for(i = 0; i < n; i++) { // print process details
        printf("\nP%d\t%d\t%d\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt); // print process id, burst time, waiting time, turnaround time
        totwt += p[i].wt; // accumulate total waiting time
        tottt += p[i].tt; // accumulate total turnaround time
    }

    printf("\n\nAverage Waiting Time: %.2f", totwt / n); // print average waiting time
    printf("\nAverage Turnaround Time: %.2f", tottt / n); // print average turnaround time

    getch();
}
