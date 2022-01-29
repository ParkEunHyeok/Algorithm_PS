#include <iostream>
#include <queue>
using namespace std;

int s;
bool visited[2002][2002];

int bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push({{1,0},0});
    visited[1][0] = true;

    while(!q.empty()) {
        int node = q.front().first.first;
        int clip = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if(node==s) return time;

        if(node-1>=0 && !visited[node-1][clip]) {
            visited[node-1][clip] = true;
            q.push({{node-1, clip}, time+1});
        }
        if(node+clip<=2000 && !visited[node+clip][clip]) {
            visited[node+clip][clip] = true;
            q.push({{node+clip, clip}, time+1});
        }
        if(!visited[node][node]) {
            visited[node][node] = true;
            q.push({{node, node}, time+1});
        }
    }   
}

int main() {
    cin >> s;
    cout << bfs();
    return 0;
}