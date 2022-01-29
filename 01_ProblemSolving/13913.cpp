#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 200000

int n, k;
int visited[200002];

int main() {
    queue<pair<int, int> > q;

    cin >> n >> k;
    memset(visited, -1, sizeof(visited));
    q.push({n, 0});

    while(!q.empty()) {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        if(node==k) {
            int idx = node;
            stack<int> s;
            s.push(node);
            for(int i=0; i<time; i++) {
                s.push(visited[idx]);
                idx = visited[idx];
            }

            cout << time << "\n";
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            break;
        }

        if(node+1<=MAX && visited[node+1]==-1) {
            visited[node+1] = node;
            q.push({node+1, time+1});
        }
        if(node-1>=0 && visited[node-1]==-1) {
            visited[node-1] = node;
            q.push({node-1, time+1});
        }
        if(node*2<=MAX && visited[node*2]==-1) {
            visited[node*2] = node;
            q.push({node*2, time+1});
        }
    }

    return 0;
}