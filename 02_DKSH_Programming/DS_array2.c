#include <stdio.h>

int main() {
    int arr[7] = {10,20,30,40,50,60,70};
    int num;
    scanf("%d", &num);

    for(int i=0; i<7; i++) {
        if(i==num) continue;
        printf("%d ", arr[i]);
    }

    return 0;
}