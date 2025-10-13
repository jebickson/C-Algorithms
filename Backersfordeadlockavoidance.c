// not coming in practical
#include <stdio.h>
#include <conio.h>

struct da {
    int max[10], al[10], need[10];
} p[10];

main() {
    int i, j, k, r, n, tot[10], av[10], temp, done[10], count = 0;
    clrscr();

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        for (j = 0; j < r; j++) {
            printf("Max R%d: ", j + 1);
            scanf("%d", &p[i].max[j]);
        }
        for (j = 0; j < r; j++) {
            printf("Alloc R%d: ", j + 1);
            scanf("%d", &p[i].al[j]);
            p[i].need[j] = p[i].max[j] - p[i].al[j];
        }
        done[i] = 0;
    }

    for (j = 0; j < r; j++) {
        printf("Total R%d: ", j + 1);
        scanf("%d", &tot[j]);
        temp = 0;
        for (i = 0; i < n; i++)
            temp += p[i].al[j];
        av[j] = tot[j] - temp;
    }

    printf("\nSafe Sequence:\n");
    while (count < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (!done[i]) {
                for (j = 0; j < r; j++)
                    if (p[i].need[j] > av[j])
                        break;
                if (j == r) {
                    printf("P%d ", i + 1);
                    for (k = 0; k < r; k++)
                        av[k] += p[i].al[k];
                    done[i] = 1;
                    count++;
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }

    if (count == n)
        printf("\nSystem is in SAFE state.");
    else
        printf("\nDEADLOCK occurred.");

    getch();
}
