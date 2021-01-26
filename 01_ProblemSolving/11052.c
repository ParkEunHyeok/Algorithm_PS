#include <stdio.h>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main() {
    int n;
    int arr[1002]={0,};
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = 0;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(i%j==0) {
                arr[i] = max(arr[i], arr[j]*(i/j));
            }
            arr[i] = max(arr[i], arr[j] + arr[i-j]);
        }
    }

    printf("%d", arr[n]);
    return 0;
}