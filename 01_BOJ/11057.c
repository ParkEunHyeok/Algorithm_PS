#include <stdio.h>

int main() {
    int n;
    int arr[10][1002]={0,};
    scanf("%d", &n);

    for(int i=0; i<10; i++) {
        arr[i][1] = 1;
    }

    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            for(int k=j; k<10; k++) {
                arr[k][i] += arr[j][i-1];
                arr[k][i] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i=0; i<10; i++) {
        sum += arr[i][n];
    }
    printf("%d", sum%10007);
    return 0;
}