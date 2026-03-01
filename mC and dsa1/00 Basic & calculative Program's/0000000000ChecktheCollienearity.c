#include <stdio.h>
int main(){
    int x1, x2, x3, y1, y2, y3;
    printf("Enter x1, y1    x2, y2    x3, y3   :::::  ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Using cross multiplication to check collinearity
    if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1))
        printf("Yes, the points are collinear.\n");
    else
        printf("No, the points are not collinear.\n");
    return 0;
}
