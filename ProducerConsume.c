#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int in = 0; // Represents the number of items in the buffer

// Function to simulate the producer adding an item
void produce() {
    if (in < MAX) {
        in++;
        printf("Producer produces the item %d\n", in);
    } else {
        printf("Buffer is full!!\n");
    }
}

// Function to simulate the consumer removing an item
void consume() {
    if (in > 0) {
        printf("Consumer consumes item %d\n", in);
        in--;
    } else {
        printf("Buffer is empty!!\n");
    }
}

int main() {
    int c;

    printf("1.Producer\n2.Consumer\n3.Exit\n");

    // Menu for user interaction
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 3:
                exit(0); // Exit the program properly
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
