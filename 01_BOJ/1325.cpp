#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
vector<int> map[10002];
bool visited[10002];
vector<int> ans;
int cnt, mx_cnt = 0;

void dfs(int v) {
    visited[v] = true;

    for(int i=0; i<map[v].size(); i++) {
        if(!visited[map[v][i]]) {
            cnt++;
            dfs(map[v][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;

        map[B].push_back(A);
    }

    for(int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        dfs(i);

        if(mx_cnt==cnt) {
            ans.push_back(i);
        }
        if(mx_cnt < cnt) {
            ans.clear();
            ans.push_back(i);
            mx_cnt = cnt;
        }
    }

    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}