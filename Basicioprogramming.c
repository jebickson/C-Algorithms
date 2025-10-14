#include <stdio.h>

void main() {
    FILE *f1, *f2; // file =*f1 // file2 =*f2
    char buf1[50] = "justatext\n", buf2[100]; 

    f1 = fopen("file1.txt", "w+"); // w+ = read and write
    f2 = fopen("file2.txt", "w"); // w = write only

    fputs(buf1, f1); // write to file1

    printf("Enter the text: "); // take input from user
    scanf("%s", buf1); // store input in buf1
    fputs(buf1, f1); // write input to file1
    rewind(f1); // set file position to beginning of file1

    fgets(buf2, sizeof(buf2), f1); // read from file1 and store in buf2
    fputs(buf2, f2); // write buf2 to file2

    fclose(f1); // close file1
    fclose(f2); // close file2
    printf("\nFile written successfully."); // success message
}
