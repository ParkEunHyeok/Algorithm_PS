#include <stdio.h>

int main() {
    long long arr[102];
    arr[1]=1, arr[2]=1, arr[3]=1, arr[4]=2, arr[5]=2;
    
    for(int i=6; i<=100; i++) {
        arr[i] = arr[i-1] + arr[i-5];
    }

    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }

    return 0;
}