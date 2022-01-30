#include <stdio.h>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main() {
    int n;
    int arr[100001];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = arr[0];
    for(int i=1; i<n; i++) {
        arr[i] = max(arr[i], arr[i]+arr[i-1]);
        result = max(result, arr[i]);
    }

    printf("%d", result);
    return 0;
}