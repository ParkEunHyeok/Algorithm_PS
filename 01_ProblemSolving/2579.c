#include <stdio.h>

int bigger(int a, int b) {
    if(a>=b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[301] = {0};
    int cmax[301] = {0};
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    cmax[1] = arr[1];
    cmax[2] = arr[1] + arr[2];
    for(int i=3; i<=n; i++) {
        cmax[i] = bigger(arr[i]+arr[i-1]+cmax[i-3], arr[i]+cmax[i-2]);
    }

    printf("%d", cmax[n]);
    return 0;
}