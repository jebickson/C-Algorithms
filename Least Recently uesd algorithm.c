#include <stdio.h>
#include <conio.h>

int ref[50], frm[10], recent[50]; // reference string, frames, recent use tracker 
int nof, nor, pf = 0; // number of frames, number of references, page faults

int lruvictim() { // function to find the least recently used page
    int i, min = 9999, pos = -1; // initialize min to a large value and pos to -1
    for (i = 0; i < nof; i++) { // loop through frames
        if (recent[frm[i]] < min) { // if recent use is less than min
            min = recent[frm[i]]; // update min
            pos = i; // update position
        }
    }
    return pos; // return position of least recently used page
}

void main() { // main function
    int i, j, k, flag; // loop variables and flag

    clrscr();
    printf("LRU Page Replacement Algorithm\n"); // title
    printf("Enter number of frames: "); // take number of frames as input
    scanf("%d", &nof); // store input in nof
    printf("Enter number of reference string elements: "); // take number of references as input
    scanf("%d", &nor); // store input in nor
    printf("Enter reference string: "); // take reference string as input
    for (i = 0; i < nor; i++) // loop to take each reference
        scanf("%d", &ref[i]); // store input in ref array

    for (i = 0; i < nof; i++) frm[i] = -1; // initialize frames to -1

    for (i = 0; i < nor; i++) { // loop through each reference
        flag = 0; // reset flag

        for (j = 0; j < nof; j++) { // check if page is already in frame
            if (frm[j] == ref[i]) { // if page is found
                flag = 1; // set flag to 1
                break; // break loop
            }
        }

        if (!flag) { // if page not found in frame
            int pos; // position to replace
            if (i < nof) // if frames are not full yet
                pos = i; // use next empty frame
            else // if frames are full
                pos = lruvictim(); // find least recently used page to replace
            frm[pos] = ref[i]; // replace page in frame
            pf++; // increment page fault count
        }

        recent[ref[i]] = i; // update recent use of the page

        printf("Ref %2d -> ", ref[i]); // print current reference
        for (k = 0; k < nof; k++) { // print frames
            if (frm[k] != -1) // if frame is not empty
                printf("%2d ", frm[k]); // 
            else // if frame is empty
                printf("-- "); // print placeholder
        }
        printf("\n"); // new line
    }

    printf("\nTotal Page Faults: %d", pf); // print total page faults
    getch();
}
