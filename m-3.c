#include <stdio.h>

void main() {
    int i, j, hit = 0, minIndex, pages[25], frames[10], count[10], n, f, faults = 0, time = 1;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter page numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames and count
    for (i = 0; i < f; i++) {
        frames[i] = -1;
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int found = 0;  // Use int instead of _Bool

        // Check if page exists in frame
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                count[j] = time++;
                hit++;
                break;  // Exit early to optimize
            }
        }

        if (found == 0) {  // Instead of !found
            if (i < f) {  
                // Fill empty frames first
                frames[i] = pages[i];
                count[i] = time++;
            } else {
                // Find least recently used page
                minIndex = 0;
                for (j = 1; j < f; j++) 
                    if (count[j] < count[minIndex]) 
                        minIndex = j;

                // Replace LRU page
                frames[minIndex] = pages[i];
                count[minIndex] = time++;
            }
            faults++;
        }
    }

    printf("Page Faults: %d\n", faults);
    printf("Page Hits: %d\n", hit);
}
