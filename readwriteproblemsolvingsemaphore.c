#include <stdio.h>
#include <conio.h>

int readcount = 0, writecount = 0; // number of readers and writers
int sh_var = 5; // shared variable

// Simple semaphores using integer flags
int mutex = 1, wsem = 1, rsem = 1; // mutex for critical section, wsem for writers, rsem for readers

void wait(int *s) { // P operation
    while (*s <= 0); // spin wait as long as semaphore is 0 or negative
    (*s)--;// decrement semaphore
}

void signal(int *s) { // signal operation 
    (*s)++; // increment semaphore
} 

void reader(int i) { // reader function
    wait(&rsem); // wait for reader semaphore
    wait(&mutex); // wait for mutex to enter critical section
    readcount++; // increment number of readers
    if (readcount == 1) // if first reader
        wait(&wsem); // wait for writer semaphore
    signal(&mutex); // signal mutex to leave critical section
    signal(&rsem); // signal reader semaphore

    printf("\nReader %d reads shared variable: %d", i, sh_var); // read shared variable

    wait(&mutex); // wait for mutex to enter critical section
    readcount--; // decrement number of readers
    if (readcount == 0) // if last reader
        signal(&wsem); // signal writer semaphore
    signal(&mutex); // signal mutex to leave critical section
}

void writer(int i) { // writer function
    wait(&mutex); // wait for mutex to enter critical section
    writecount++; // increment number of writers
    if (writecount == 1) // if first writer
        wait(&rsem); // wait for reader semaphore
    signal(&mutex); // signal mutex to leave critical section

    wait(&wsem); // wait for writer semaphore
    sh_var += 5; // update shared variable
    printf("\nWriter %d updates shared variable to: %d", i, sh_var); // print updated value
    signal(&wsem); // signal writer semaphore

    wait(&mutex); // wait for mutex to enter critical section
    writecount--; // decrement number of writers
    if (writecount == 0) // if last writer
        signal(&rsem); // signal reader semaphore
    signal(&mutex); // signal mutex to leave critical section
}

void main() { // main function
    int i; // loop variable
    clrscr(); // clear screen

    // Simulate multiple readers and writers
    reader(1);
    writer(1);
    reader(2);
    reader(3);
    writer(2);
    reader(4);

    getch();
}
