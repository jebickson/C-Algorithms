#include <stdio.h>
//#include <conio.h>

void sort(int a[], int n) { // function to sort array
    int i, j, t; // loop variables and temp variable
    // Bubble sort algorithm
    for(i = 0; i < n - 1; i++) { // outer loop
        for(j = i + 1; j < n; j++) { // inner loop
            if(a[i] > a[j]) { // 
                t = a[i];// swap if out of order
                a[i] = a[j]; // swap
                a[j] = t; // swap
            }
        }
    }
}

void main() { // main function
    FILE *fp; // file pointer
    int i, a[50], n; // loop variable, array to hold numbers, number of elements

    //clrscr();

    printf("Enter number of elements: "); // prompt for number of elements
    scanf("%d", &n); // read number of elements

    printf("Enter %d numbers:\n", n); // prompt for numbers
    // Read numbers into array
    for(i = 0; i < n; i++) { // loop to read numbers
        scanf("%d", &a[i]); // read number into array
    }

    // --- Write to file ---
    fp = fopen("DATA.TXT", "w"); // open file in write mode
    for(i = 0; i < n; i++) { // loop to write numbers to file
        fprintf(fp, "%d\n", a[i]); // write one per line for safety
    }
    fclose(fp); // close file

    // Clear array
    for(i = 0; i < n; i++) { // loop to clear array
        a[i] = 0; // set each element to 0
    }

    // --- Read from file ---
    fp = fopen("DATA.TXT", "r"); // open file in read mode
    for(i = 0; i < n; i++) { // loop to read numbers from file
        fscanf(fp, "%d", &a[i]); // read number into array
    }
    fclose(fp); // close file

    // Sort
    sort(a, n); // call sort function

    // Display
    printf("\nSorted Numbers:\n"); // header for sorted numbers
    for(i = 0; i < n; i++) { // loop to display sorted numbers
        printf("%d ", a[i]); //
    }

    //getch(); // wait for key press
}
