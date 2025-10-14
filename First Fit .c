#include <stdio.h>
//#include <conio.h>
#define MAX 25 // maximum number of blocks and files

void main() {
    int b[MAX], f[MAX], frag[MAX], bf[MAX] = {0}; // block sizes, file sizes, fragmentation, block free status
    int nb, nf, i, j; // number of blocks, number of files, loop variables 

    //clrscr();
    printf("Memory Management Scheme - First Fit\n");// title
    printf("Enter number of blocks: "); // take number of blocks as input
    scanf("%d", &nb); // store input in nb
    printf("Enter number of files: "); // take number of files as input
    scanf("%d", &nf); // store input in nf

    printf("Enter block sizes:\n"); // prompt for block sizes
    for (i = 0; i < nb; i++) { // loop to take each block size
        printf("Block %d: ", i + 1); // prompt for block size
        scanf("%d", &b[i]); // store input in b array
    }

    printf("Enter file sizes:\n"); // prompt for file sizes
    for (i = 0; i < nf; i++) { // loop to take each file size
        printf("File %d: ", i + 1); // prompt for file size
        scanf("%d", &f[i]); // store input in f array
    }

    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n"); // print table header

    for (i = 0; i < nf; i++) { // loop through each file
        for (j = 0; j < nb; j++) { // loop through each block
            if (bf[j] == 0 && b[j] >= f[i]) { // if block is free and can accommodate file
                frag[i] = b[j] - f[i]; // calculate fragmentation
                bf[j] = 1; // mark block as allocated
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], j + 1, b[j], frag[i]); // print file and block details
                break; // break inner loop to move to next file
            }
        }
        if (j == nb) { // if no suitable block was found
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]); // print file details with not allocated message
        }
    }

    //getch();
}
