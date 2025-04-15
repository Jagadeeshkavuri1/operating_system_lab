#include<stdio.h>

int main() {
    int n, f, a[30], frames[10], hit = 0, fault = 0, index = 0;

    printf("Enter no of Pages: ");
    scanf("%d", &n);
    printf("Enter Page Numbers: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    printf("Enter no of Frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++) 
        frames[i] = -1;

    for (int j = 0; j < n; j++) {
        int flag = 0;
        for (int i = 0; i < f; i++) {
            if (frames[i] == a[j]) {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {  // Replaced !flag with flag == 0
            frames[index] = a[j];
            index = (index + 1) % f;
            fault++;
        }

        for (int i = 0; i < f; i++) 
            printf("%d ", frames[i]);
        
        printf("\n");
    }

    printf("Page Faults: %d\nPage Hits: %d\n", fault, hit);
    return 0;
}
