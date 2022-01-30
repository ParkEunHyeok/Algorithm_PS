#include <stdio.h>

int main() {
    int n, arr[1001] = {};
    arr[0] = 1; arr[1] = 1;
    scanf("%d",&n);
    for(int i=2; i<=n; i++) {
        arr[i] = (arr[i-1] + (arr[i-2]*2)) % 10007;
    }
    printf("%d",arr[n]);

    return 0;
}

//d[i] = d[i-1] + (d[i-2]*2)