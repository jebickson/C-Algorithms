//not coming in practical
#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, n, f, ref[50], frm[10], pf = 0, flag, pos = 0;

    clrscr();
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < f; i++)
        frm[i] = -1;  // Initialize frames to -1

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frm[pos] = ref[i];
            pos = (pos + 1) % f;  // Move in circular FIFO manner
            pf++;

            printf("%d\t", ref[i]);
            for (j = 0; j < f; j++) {
                if (frm[j] != -1)
                    printf("%d ", frm[j]);
                else
                    printf("- ");
            }
            printf("\n");
        } else {
            printf("%d\tNo Replacement\n", ref[i]);
        }
    }

    printf("\nTotal Page Faults = %d", pf);
    getch();
}
