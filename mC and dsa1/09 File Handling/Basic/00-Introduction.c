#include <stdio.h>
int main(){
     fopen("file name","mode");  //Returns an Pointer


//         MODE's
     "r" - read mode
     "w" - write mode
     "a" - append mode

     "r+"
     "w+" 
     "a+"

return 0;}


//FILE data type ke andar ki science (Inbuild)
typedef struct{
     int fd;                    //File Descriptor
     unsigned char *buf;        // Buffer
     size_t size;                //Size of file
     size_t pos;              //Current position in file
} FILE;