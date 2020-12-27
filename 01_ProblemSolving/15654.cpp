#include <iostream>
#include <algorithm>

using namespace std;

//nPm
int n, m;
int arr[8];
int number[8];
int visit[8];

void backtracking(int cnt) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        return;
    }

    for(int i=0; i<n; i++) {
        // 방문한 적 있으면 건너뜀.
        if(visit[i]) continue;

        // 방문함 표시
        visit[i] = 1;
        // arr 배열에 집어넣기
        arr[cnt] = number[i];
        // 카운트 1늘리고 재귀 동작
        backtracking(cnt + 1);
        // 뒤로 back
        visit[i] = 0;
    }
}

int main() {
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &number[i]);
    }
    sort(number, number+n);
    backtracking(0);

    return 0;
}