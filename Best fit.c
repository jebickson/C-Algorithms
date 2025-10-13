#include <stdio.h>
#include <conio.h>
#define MAX 25 // maximum number of blocks and files

void main() { // main function
    int b[MAX], f[MAX], frag[MAX], bf[MAX] = {0}, alloc[MAX] = {0}; // block sizes, file sizes, fragmentation, block free status, allocation status
    int nb, nf, i, j, temp, best; // number of blocks, number of files, loop variables, temp variable, best block index

    clrscr(); // clear screen
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

    for (i = 0; i < nf; i++) { // loop through each file
        best = -1; // initialize best block index to -1
        for (j = 0; j < nb; j++) { // loop through each block
            if (bf[j] == 0 && b[j] >= f[i]) { // if block is free and can accommodate file
                if (best == -1 || b[j] < b[best]) // if it's the first suitable block or smaller than current best
                    best = j; // update best block index
            }
        }

        if (best != -1) { // if a suitable block was found
            alloc[i] = best + 1; // allocate block to file (1-based index)
            frag[i] = b[best] - f[i]; // calculate fragmentation
            bf[best] = 1; // mark block as allocated
        }
    }

    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment"); // print table header
    for (i = 0; i < nf; i++) { // loop through each file
        if (alloc[i] != 0) // if file was allocated a block
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], alloc[i], b[alloc[i] - 1], frag[i]); // print file and block details
        else // if file was not allocated a block
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, f[i]); // print file details with not allocated message
    }

    getch();
}
