#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
void task1() {
for (int i = 1; i <= 5; ++i) {
printf("Task 1: %d\n", i);
sleep(1); // Sleep for 1 second
}
}
void task2() {
for (int i = 1; i <= 5; ++i) {
printf("Task 2: %d\n", i);
sleep(1); // Sleep for 1 second
}
}
int main() {
// Run task 1
task1();
// Run task 2
task2();
printf("Main thread: Both tasks have finished.\n");
return EXIT_SUCCESS;
}


