#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int right = id;
    int left = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Think
        printf("Philosopher %d is thinking.\n", id);
        usleep(1000000);

        // Pick up chopsticks
        pthread_mutex_lock(&chopsticks[right]);
        printf("Philosopher %d picked up the right chopstick.\n", id);
        pthread_mutex_lock(&chopsticks[left]);
        printf("Philosopher %d picked up the left chopstick.\n", id);

        // Eat
        printf("Philosopher %d is eating.\n", id);
        usleep(1000000);

        // Put down chopsticks
        pthread_mutex_unlock(&chopsticks[right]);
        printf("Philosopher %d put down the right chopstick.\n", id);
        pthread_mutex_unlock(&chopsticks[left]);
        printf("Philosopher %d put down the left chopstick.\n", id);
    }
}

int main() {
    int i;
    int ids[NUM_PHILOSOPHERS];

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}

