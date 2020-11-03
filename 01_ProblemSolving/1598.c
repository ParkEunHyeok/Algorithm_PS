#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int ax = (a-1) / 4; //2
    int ay = (a-1) % 4; //2
    int bx = (b-1) / 4; //8
    int by = (b-1) % 4; //0

    int result_x, result_y;
    if(ax >= bx) result_x = ax - bx;
    else result_x = bx - ax;
    if(ay >= by) result_y = ay - by;
    else result_y = by - ay;

    printf("%d", result_x + result_y);

    return 0; 
}