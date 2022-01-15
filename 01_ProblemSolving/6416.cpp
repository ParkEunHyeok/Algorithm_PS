#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1004

vector<int> tree[MAX];
bool visited[MAX];
bool exist[MAX];
bool flag;
int root;

void dfs(int node) {
    visited[node] = true;

    if(tree[node].size()>1) {
        flag = false;
        return;
    }
    else if(tree[node].size()==0) {
        if(!exist[node]) return;
        
        if(!root) root = node;
        else if(root!=node) flag = false;
        return;
    }

    if(!visited[tree[node][0]]) dfs(tree[node][0]);
    else flag = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int testcase = 0;
    int a, b;

    while(1) {
        cin >> a >> b;

        if(a==-1 && b==-1) break;
        if(a==0 && b==0) {
            flag = true;
            root = 0;

            for(int i=1; i<MAX; i++) {
                if(!flag) break;
                memset(visited, 0, sizeof(visited));
                dfs(i);
            }

            testcase++;
            if(flag) cout << "Case " << testcase << " is a tree.\n";
            else cout << "Case " << testcase << " is not a tree.\n";
            memset(tree, 0, sizeof(tree));
            memset(exist, 0, sizeof(exist));
        } else {
            tree[b].push_back(a);
            exist[a] = true;
            exist[b] = true;
        }
    }

    return 0;
}