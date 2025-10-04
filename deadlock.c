#include <stdio.h>

int main() {
    int n, r;
    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &r);

    int allocation[n][r], max[n][r], need[n][r], available[r];
    int finish[n], safeSeq[n], index = 0;

    // Input Allocation Matrix
    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max Matrix
    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Vector
    printf("Enter Available vector:\n");
    for (int j = 0; j < r; j++) {
        scanf("%d", &available[j]);
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize Finish Array
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == r) {
                    for (int k = 0; k < r; k++) {
                        available[k] += allocation[i][k];
                    }
                    safeSeq[index++] = i;
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) {
            // no process can be allocated
            break;
        }
    }

    int deadlock = 0;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = 1;
        }
    }

    if (deadlock) {
        printf("Deadlock: ");
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock\nSafe sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    }

    return 0;
}
