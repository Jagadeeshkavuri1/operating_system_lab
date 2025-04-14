#include<stdio.h>
#define MAX 25
int main() {
    int frag[MAX], block[MAX], file[MAX], bf[MAX], ff[MAX];
    int nb, nf, i, j, temp;
    printf("\nMemory Management Scheme - First Fit\n");
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of files: ");
    scanf("%d", &nf);
    printf("\nEnter block sizes:\n");
    for(i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
        bf[i] = 0;  // Initialize bf[i] to 0 manually here
    }
    printf("\nEnter file sizes:\n");
    for(i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &file[i]);
    }
    for(i = 0; i < nf; i++) {
        for(j = 0; j < nb; j++) {
            if(bf[j] == 0 && block[j] >= file[i]) {
                ff[i] = j;
                frag[i] = block[j] - file[i];
                bf[j] = 1;
                break;
            }
        }
        if(j == nb) { // no block found
            ff[i] = -1;
            frag[i] = -1;
        }
    }
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for(i = 0; i < nf; i++) {
        if(ff[i] != -1)
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", i + 1, file[i], ff[i] + 1, block[ff[i]], frag[i]);
        else
            printf("\n%d\t%d\t\tNot Allocated", i + 1, file[i]);
    }
    return 0;
}