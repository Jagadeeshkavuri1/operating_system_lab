#include <stdio.h>

// Function to find the optimal page to replace
int findOptimal(int frames[], int pages[], int n, int current, int f) {
    for (int i = 0; i < f; i++) {
        int j;
        for (j = current + 1; j < n; j++)
            if (frames[i] == pages[j])
             break;
        if (j == n)
         return i;
    }
    return 0; // Default replacement index
}

// Optimal Page Replacement Algorithm
void optimalPageReplacement(int pages[], int n, int f) {
    int frames[f], faults = 0, hits = 0;

    for (int i = 0; i < f; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) { hits++; found = 1; break; }
        }
        if (!found) {
            int replaceIdx = (i < f) ? i : findOptimal(frames, pages, n, i, f);
            frames[replaceIdx] = pages[i];
            faults++;
        }

        // Display current frame state
        printf("Step %d: ", i + 1);
        for (int j = 0; j < f; j++) printf("%d ", frames[j] == -1 ? -1 : frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\nTotal Page Hits: %d\n", faults, hits);
}

int main() {
    int n, f;
    printf("Enter number of pages: "); scanf("%d", &n);
    int pages[n];
    printf("Enter page numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: "); scanf("%d", &f);

    optimalPageReplacement(pages, n, f);
    return 0;
}
