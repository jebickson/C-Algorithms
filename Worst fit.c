#include <stdio.h>
#include <conio.h>
#define MAX 25 // maximum number of blocks and files

void main() {
    int b[MAX], f[MAX], frag[MAX], alloc[MAX], nb, nf, i, j, worst, temp; // block sizes, file sizes, fragmentation, allocation status, number of blocks, number of files, loop variables, worst block index

    clrscr();
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
        printf("File %d: ", i + 1); 
        scanf("%d", &f[i]); // store input in f array
        alloc[i] = -1; // initialize allocation status to -1 (not allocated)
    }

    for (i = 0; i < nf; i++) { // loop through each file
        worst = -1; // initialize worst block index to -1
        for (j = 0; j < nb; j++) { // loop through each block
            if (b[j] >= f[i]) { // if block can accommodate file
                if (worst == -1 || b[j] > b[worst]) // if it's the first suitable block or larger than current worst
                    worst = j; // update worst block index
            }
        }
        if (worst != -1) { // if a suitable block was found
            alloc[i] = worst + 1; // allocate block to file (1-based index)
            frag[i] = b[worst] - f[i]; // calculate fragmentation
            b[worst] = 0; // mark block as allocated by setting its size to 0
        }
    }

    printf("\nFileNo\tFileSize\tBlockNo\tBlockSize\tFragment"); // print table header
    for (i = 0; i < nf; i++) { // loop through each file
        if (alloc[i] != -1) // if file was allocated a block
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], alloc[i], f[i] + frag[i], frag[i]); // print file and block details
        else // if file was not allocated a block
            printf("\n%d\t%d\t\tNot Allocated", i + 1, f[i]); // print file details with not allocated message
    }

    getch();
}
