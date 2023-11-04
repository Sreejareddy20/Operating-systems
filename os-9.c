#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
	int key_t;
	int key;
	int SHM_SIZE;
	int IPC_CREAT;
	int IPC_RMID;
	int shm_ptr;
    key_t = ftok("shmfile", 65); 
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    if (SHM_SIZE ==(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    strcpy(shm_ptr, "Hello, shared memory!");
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
printf("Data written to shared memory: %s\n", shm_ptr);
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
    return 0;
}
