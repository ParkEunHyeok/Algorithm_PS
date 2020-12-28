#include <stdio.h>

int main() {
    int n, m;   // 표의 크기, 합을 구해야 하는 횟수
    scanf("%d%d", &n, &m);
    
    int arr[1026][1026]={0,};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int number;
            scanf("%d", &number);
            arr[i][j] = number+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];

        }
    }

    for(int i=0; i<m; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        int result;
        result = arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1];
        printf("%d\n", result);
    }

    return 0;
}