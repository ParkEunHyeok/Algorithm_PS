#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    vector<string> s;
    map<string, int> idx;
    vector<int> v[1002];
    int indegree[1002] = {0,};
    queue<int> q;

    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        s.push_back(str);
    }
    sort(s.begin(), s.end());
    for(int i=0; i<n; i++) idx[s[i]] = i;

    cin >> m;
    for(int i=0; i<m; i++) {
        string a, b;
        cin >> a >> b;
        indegree[idx[a]]++;
        v[idx[b]].push_back(idx[a]);
    }

    vector<string> root;
    for(int i=0; i<n; i++) {
        if(!indegree[i]) {
            root.push_back(s[i]);
            q.push(i);
        }
    }

    vector<int> children[1002];
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<v[cur].size(); i++) {
            indegree[v[cur][i]]--;
            if(!indegree[v[cur][i]]) {
                children[cur].push_back(v[cur][i]);
                q.push(v[cur][i]);
            }
        }
    }

    cout << root.size() << "\n";
    for(int i=0; i<root.size(); i++) {
        cout << root[i] << " ";
    }
    cout << "\n";

    for(int i=0; i<n; i++) {
        cout << s[i] << " ";
        cout << children[i].size() << " ";

        sort(children[i].begin(), children[i].end());
        for(int j=0; j<children[i].size(); j++) {
            cout << s[children[i][j]] << " ";
        }
        cout << "\n";
    }

    return 0;
}