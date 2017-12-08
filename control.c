#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 23456

int main(int argc, char **argv){
  if(argc < 2) {
    printf("not enough arguments\n");
  }
  else if(!strcmp(argv[1], "-c")){
    int semid = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (semid == -1){
      printf("the sema[hore already exists\n");
    }
    else{
      int val;
      sscanf(argv[2], "%d" , &val);
      semctl(semid, 0 , SETVAL, val);
      printf("Semaphore created: %d\n", KEY);
      printf("Value : %d\n", val);
    }
  }
  else if(!strcmp(argv[1], "-v")){
    int semid = semget(KEY, 0,0);
    printf("Semaphor value : %d\n", semctl(semid,0,GETVAL));
  }
  else if(!strcmp(argv[1], "-r")){
    int semid = semget(KEY,0,0);
    printf("Semaphore removed : %d\n" , semctl(semid, 0 , IPC_RMID));

  }
  return 0;
}
