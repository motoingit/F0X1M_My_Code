


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NO_OF_PHILOSOPHER 5
sem_t spoon[NO_OF_PHILOSOPHER];
// ================= PHILOSOPHER =================
void *philosopher(void *arg){
  int id = *(int *)arg;
  int right = id;
  int left = (id + 1) % NO_OF_PHILOSOPHER;
  if (id % 2 == 0){ // Even philosopher → Right first
    sem_wait(&spoon[right]);
    sem_wait(&spoon[left]);
  }else{ // Odd philosopher → Left first
    sem_wait(&spoon[left]);
    sem_wait(&spoon[right]);
  }
  //^ CS
  printf("P%d is EATING\n", id);
  sleep(1);
  // Put down spoons
  sem_post(&spoon[left]);
  sem_post(&spoon[right]);
}

// ================= MAIN =================
int main(){
  pthread_t philosopherThread[NO_OF_PHILOSOPHER];
  int id[NO_OF_PHILOSOPHER];
  // Initialize spoons
  for (int i = 0; i < NO_OF_PHILOSOPHER; i++)
    sem_init(&spoon[i], 0, 1);
  // Create philosophers
  for (int i = 0; i < NO_OF_PHILOSOPHER; i++){
      id[i] = i;
      pthread_create(
        &philosopherThread[i],
        NULL,
        philosopher,
        &id[i]
      );
  }
  // Wait for philosophers
  for (int i = 0; i < NO_OF_PHILOSOPHER; i++)
    pthread_join(philosopherThread[i], NULL);
  // Cleanup
  for (int i = 0; i < NO_OF_PHILOSOPHER; i++)
    sem_destroy(&spoon[i]);
return 0;}

