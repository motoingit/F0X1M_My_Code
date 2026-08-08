/*
gcc fork.c -o fork
./fork
*/

#include<stdio.h>
#include<unistd.h>

void print(int pid){
  if (pid == -1)
      printf("Fork failed\n");
  else if (pid == 0)
      printf("Child: pid returned = %d\n", pid);
  else
      printf("Parent: child PID = %d\n", pid);
}


int main(){
//

//fork 1
print(fork());

if(fork()){

  print(fork());;
  
}

//
return 0;}
