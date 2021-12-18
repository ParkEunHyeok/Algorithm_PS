#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 300001

vector<int> v[MAX];
bool visited[MAX];
queue<int> q;
bool flag = false;
int result;
bool rootFlag = false;
int cnt = 0;

void dfs(int n) {
    visited[n] = true;
    cnt++;

    for(int i=0; i<v[n].size(); i++) {
        int flag = false;
        for(int j=0; j<v[i].size(); j++) { 
            if(v[i][j]==v[n][i]) {
                flag = true;    // 양방향
                break;
            }
        }
        if(!flag) {
            cout << n << " " << v[n][i] << "\n";
            rootFlag = false;
            continue;
        }
        if(visited[v[n][i]]==true) continue;
        dfs(v[n][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int a, b, m;
        cin >> a >> b >> m;

        if(m==0) {
            v[a].push_back(b);
            v[b].push_back(a);
        } else {
            v[b].push_back(a);
            q.push(a);
        }
    }

    if(q.empty()) {
        cout << n;
        return 0;
    }

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << "\n";
        q.pop();
        rootFlag = true;
        cnt = 0;

        dfs(cur);

        if(rootFlag) {
            if(flag==true) {
                result = 0;
                break;
            }
            flag = true;
            result = cnt;
        }
    }

    cout << result;
    return 0;
}