#include <stdio.h>

int main() {
    int n, count=0;
    int arr[1002]={0,}; // 0:소수, 1:소수X
    arr[0]=1, arr[1]=1;

    // 에라토스테네스의 체
    for(int i=2; i<=1000; i++) {
        int weight=2;
        while(i*weight<=1000) {
            arr[i*weight] = 1;
            weight++;
        }
    }

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int number;
        scanf("%d", &number);
        if(arr[number]==0) count++;
    }
    printf("%d", count);

    return 0;
}