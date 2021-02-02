#include <stdio.h>

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    int n, mx=0, sum=0;
    int arr[1002]={0,};
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        mx = max(mx, arr[i]);
        sum += arr[i];
    }
    sum += mx * (n-2);

    printf("%d", sum);
    return 0;
}