#include <stdio.h>

int main() {
    int n, m;   // 세로n, 가로m
    int count = 0;
    char arr[101][101] = {'\0',};
    int value[51][51] = {0,};
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='.') {
                for(int k=0; k<n; k++) value[k][j] ++;
                for(int k=0; k<m; k++) value[i][k] ++;
                value[i][j]--;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(value[i][j]>=2) {
                count++;
                for(int k=0; k<n; k++) value[k][j] = 0;
                for(int k=0; k<m; k++) value[i][k] = 0;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(value[i][j]==1) {
                count++;
                for(int k=0; k<n; k++) value[k][j] = 0;
                for(int k=0; k<m; k++) value[i][k] = 0;
            }
        }
    }

    printf("%d", count);

    return 0;
}