#include <iostream>
#include <vector>
using namespace std;

int n, s;   // 정수의 개수, 정수
int result = 0;
vector<int> v;

void dfs(int idx, int sum) {
    if(idx==n) return;
    if((sum+v[idx])==s) result++;

    dfs(idx+1, sum);
    dfs(idx+1, sum+v[idx]);
}

int main() {
    scanf("%d%d", &n, &s);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    dfs(0,0);
    printf("%d", result);

    return 0;
}