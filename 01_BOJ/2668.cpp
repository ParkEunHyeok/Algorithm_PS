#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> map[102];
bool visited[102];
vector<int> ans;
vector<int> dfs_node;
int target_num;

void dfs(int v, int depth) {
    visited[v] = true;
    dfs_node.push_back(v);

    for(int i=0; i<map[v].size(); i++) {
        if(map[v][i] == target_num) {
            for(int i=0; i<dfs_node.size(); i++) {
                ans.push_back(dfs_node[i]);
                break;
            }
        }

        if(!visited[map[v][i]]) {
            dfs(map[v][i], depth+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        int node;
        cin >> node;

        map[i].push_back(node);
    }

    for(int i=1; i<=n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs_node.clear();
        target_num = i;
        dfs(i, 1);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}