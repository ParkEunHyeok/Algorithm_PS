#include <stdio.h>

int main() {
    int n, m;   // 세로n, 가로m
    int row_count = 0, col_count = 0;
    int row[101]={0,}, col[101]={0,};
    char arr[101][101] = {'\0',};
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='X') {
                row[i]++;
                col[j]++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(!row[i]) row_count++;
    }
    for(int i=0; i<m; i++) {
        if(!col[i]) col_count++;
    }

    if(row_count > col_count) printf("%d", row_count);
    else printf("%d", col_count);

    return 0;
}