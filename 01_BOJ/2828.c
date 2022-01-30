#include <stdio.h>

int main() {
    int N, M, J;
    int distance=0, left, right, move, apple;

    scanf("%d%d%d", &N, &M, &J);
    left = 1;
    for(int i=0; i<J; i++) {
        scanf("%d", &apple);
        right = left + M - 1;
        if(apple < left) {  // 왼쪽
            move = left - apple;
            left = apple;
            distance += move;
        }
        else if(apple > right) {
            move = apple - right;
            left += move;
            distance += move;
        }
        else {
            continue;
        }
    }

    printf("%d", distance);
    return 0;
}