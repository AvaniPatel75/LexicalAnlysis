#include <stdio.h>
int main() {
    FILE *fp1, *fp2;
    fp1 = fopen("E:/Sem-6/ATCC_Lab/Input.txt", "r");
    if (fp1 == NULL) {
        printf("File Not Found");
        return 0;
    }
    fp2 = fopen("E:/Sem-6/ATCC_Lab/Output.txt", "w");
    char ch;
    int prev;   
    while (fscanf(fp1, "%c", &ch) != EOF) {
        if (ch == '/') {
            prev = fscanf(fp1, "%c", &ch);
            if (prev == EOF) {
                fprintf(fp2, "%c", '/');
                break;
            }
            if (ch == '/') {
                while (fscanf(fp1, "%c", &ch) != EOF && ch != '\n') {
                    // skip single-line comment
                }
                printf("Single line comment removed\n");
            } else if (ch == '*') {
                prev = 0;
                while (fscanf(fp1, "%c", &ch) != EOF) {
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                printf("Multi line comment removed\n");
            } else {
                ungetc(ch, fp1);
                fprintf(fp2, "%c", '/');
            }
        } else {
            fprintf(fp2, "%c", ch);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
