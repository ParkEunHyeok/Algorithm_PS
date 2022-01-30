#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n, m, r;   // 세로, 가로, 합을 구해야 하는 횟수
    scanf("%d%d%d", &n, &m, &r);
    
    vector<vector<int>> v(n+1, vector<int>(max(m,n)+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int number;
            scanf("%d", &number);
            v[i][j] = number+v[i-1][j]+v[i][j-1]-v[i-1][j-1];

        }
    }

    for(int i=0; i<r; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        int result, num;
        result = v[y2][x2] - v[y2][x1-1] - v[y1-1][x2] + v[y1-1][x1-1];
        num = (y2-y1+1) * (x2-x1+1);
        printf("%d\n", result/num);
    }

    return 0;
}