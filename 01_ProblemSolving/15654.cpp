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
        if(visit[i]) continue;

        visit[i] = 1;
        arr[cnt] = number[i];
        backtracking(cnt + 1);

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