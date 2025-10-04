#include <stdio.h>

int main() {
    int p1, p2;
    int counter = 0;

    // Input number of increments
    printf("Enter how many times Process 1 should increment the counter: ");
    scanf("%d", &p1);

    printf("Enter how many times Process 2 should increment the counter: ");
    scanf("%d", &p2);

    int expected = p1 + p2;

    // Process 1 increments
    for (int i = 0; i < p1; i++) {
        counter++;
    }

    // Process 2 increments
    for (int i = 0; i < p2; i++) {
        counter++;
    }

    // Display result
    printf("Final counter value (expected: %d): %d\n", expected, counter);

    return 0;
}
