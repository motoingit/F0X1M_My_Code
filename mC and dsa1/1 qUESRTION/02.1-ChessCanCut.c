#include <stdio.h>
#include <stdlib.h>
int main(){
    int px, py, qx, qy;
    printf("Enter the Postion of Pawn : ");
    scanf("%d %d",&px, &py);
    printf("Enter the Postion of Queen : ");
    scanf("%d %d",&qx, &qy);
    if(px < 0 || px > 7 || py < 0 || py > 7){
        printf("Pawn Position is out of range.\n");
        return 0;
    }
    if(px == qx && py == qy){
        printf("Pawn and Queen are in same position.\n");
        return 0;
    }

    if(px == qx || py == qy){
        printf("Horizontally Queen Can cut the Piece.\n");
        return 0;
    }
    else if(abs(px - qx) == abs(py - qy)){
        printf("Diagonally Queen Can cut the Piece.\n");
        return 0;
    }
    else{
        printf("Queen Can't cut the Piece.\n");
        return 0;
    }
return 0;}