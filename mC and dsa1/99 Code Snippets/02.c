#include <stdio.h>
#include <string.h>

struct engine { int oil; };

int main(){

struct engine car = {10}; 
struct engine bike = {.oil = 15}; 

return 0;}