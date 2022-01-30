#include <stdio.h>

int main() {
    int n;
    int arr[1000002];
    
    scanf("%d", &n);
    arr[1] = 1, arr[2] = 2;

    for(int i=3; i<=n; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 15746;
    }

    printf("%d", arr[n]);
    return 0;
}