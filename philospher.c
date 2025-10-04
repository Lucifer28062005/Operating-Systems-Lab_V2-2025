#include <stdio.h>

#define N 5

// States of philosophers
enum { THINKING, HUNGRY, EATING } state[N];

// Chopstick availability (0 = free, 1 = taken)
int chopstick[N];

// Function to check if philosopher can eat
int can_eat(int phil) {
    int left = phil;
    int right = (phil + 1) % N;
    return (!chopstick[left] && !chopstick[right]);
}

// Pickup chopsticks
void pickup(int phil) {
    printf("Philosopher %d is now hungry\n", phil);
    state[phil] = HUNGRY;

    if (can_eat(phil)) {
        int left = phil;
        int right = (phil + 1) % N;
        chopstick[left] = 1;
        chopstick[right] = 1;
        state[phil] = EATING;
        printf("Philosopher %d starts eating\n", phil);
    } else {
        printf("Philosopher %d cannot eat now\n", phil);
    }
}

// Put down chopsticks
void putdown(int phil) {
    if (state[phil] == EATING) {
        int left = phil;
        int right = (phil + 1) % N;
        chopstick[left] = 0;
        chopstick[right] = 0;
        state[phil] = THINKING;
        printf("Philosopher %d stops eating and starts thinking\n", phil);
    } else if (state[phil] == HUNGRY) {
        state[phil] = THINKING;
        printf("Philosopher %d was hungry but goes back to thinking\n", phil);
    } else {
        printf("Philosopher %d is already thinking\n", phil);
    }
}

int main() {
    int choice, phil;

    for (int i = 0; i < N; i++) {
        state[i] = THINKING;
        chopstick[i] = 0;
    }

    printf("Choices:\n1. Philosopher hungry\n2. Philosopher puts down chopsticks\n3. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 3) break;

        if (choice == 1) {
            printf("Which philosopher (0-%d) is hungry: ", N - 1);
            scanf("%d", &phil);
            pickup(phil);
        } else if (choice == 2) {
            printf("Which philosopher (0-%d) puts down chopsticks: ", N - 1);
            scanf("%d", &phil);
            putdown(phil);
        } else {
            printf("Invalid choice\n");
            continue;
        }

        printf("\nStates:\n");
        for (int i = 0; i < N; i++) {
            const char *s = state[i] == THINKING ? "Thinking"
                           : state[i] == HUNGRY ? "Hungry" : "Eating";
            printf("Philosopher %d: %s\n", i, s);
        }

        printf("\nChopsticks:\n");
        for (int i = 0; i < N; i++) {
            printf("Chopstick %d: %s\n", i, chopstick[i] ? "Taken" : "Free");
        }
    }

    return 0;
}
