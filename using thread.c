#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
void* task1(void* arg) {
for (int i = 1; i <= 5; ++i) {
printf("Task 1: %d\n", i);
sleep(1); // Sleep for 1 second
}
pthread_exit(NULL);
}
void* task2(void* arg) {
for (int i = 1; i <= 5; ++i) {
printf("Task 2: %d\n", i);
sleep(1); // Sleep for 1 second
}
pthread_exit(NULL);
}
int main() {
pthread_t thread1, thread2;
// Create thread 1
if (pthread_create(&thread1, NULL, task1, NULL) != 0) {
printf("Error creating thread 1\n");
return EXIT_FAILURE;
}
// Create thread 2
if (pthread_create(&thread2, NULL, task2, NULL) != 0) {
printf("Error creating thread 2\n");
return EXIT_FAILURE;
}
// Wait for thread 1 to finish
if (pthread_join(thread1, NULL) != 0) {
printf("Error joining thread 1\n");
return EXIT_FAILURE;
}
// Wait for thread 2 to finish
if (pthread_join(thread2, NULL) != 0) {
printf("Error joining thread 2\n");
return EXIT_FAILURE;
}
printf("Main thread: Both threads have finished.\n");
return EXIT_SUCCESS;
}
