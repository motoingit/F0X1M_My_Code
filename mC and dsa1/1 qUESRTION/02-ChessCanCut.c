#include <stdio.h>
int main(){
    int px, py, qx, qy;
    printf("Enter the Postion of Pawn : ");
    scanf("%d %d",&px, &py);
    printf("Enter the Postion of Queen : ");
    scanf("%d %d",&qx, &qy);

    ////+ y asix
    int x = 0, y = 0;
    while(x < 8){
        if(px == x && py == qy){
            printf("Can cut on y axis.\n");
            return 0;
        }
        x++;
    }
    printf("Cant cut on y axis.\n");

//// + x axis
    while(x < 8){
        if(px == qx && py == y){
            printf("Can cut on x axis.\n");
            return 0;
        }
        y++;
    }
    printf("Can't cut on x axis. \n");

///////* main diag
    x = qx, y = qy;
    while(x != 0 && y != 0){
        x--,y--;
    }

    while(x != 8 && y != 8){
        if(px == x && py == y){
            printf("Can cut in main diagonal.\n");
            return 0;
        }
        x++,y++;
    }
    printf("Can't cut in main diagonal. \n");

    ////* sec dia
    x = qx, y = qy;
    while(x != 0 && y != 0){
        x++, y--;
    }

    while(8 != x &&  8 != y){
        if(px == x && py == y){
            printf("Can cut in sec diagonal.\n");
            return 0;
        }
        x--,y++;
    }
    printf("Can't cut in sec diagonal. \n");
    printf("So the Pawn can't be cut by Queen.\n");

return 0;}