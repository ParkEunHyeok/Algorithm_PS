#include <stdio.h>

int main() {
    int arr[7] = {10,20,30,40,50,60};
    int num;
    scanf("%d", &num);

    arr[6] = num;
    for(int i=5; i>=0; i--) {
        if(num < arr[i]) {
            int temp = num;
            arr[i+1] = arr[i];
            arr[i] = num;
        }
        else break;
    }

    for(int i=0; i<7; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}