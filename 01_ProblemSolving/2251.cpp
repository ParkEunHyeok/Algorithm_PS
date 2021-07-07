#include <iostream>
#include <queue>
using namespace std;

bool visited[201][201][201];
int A, B, C;


int bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,0),C));

    while(!q.empty()) {
        int a = q.front().first.first;

    }
}

int main() {
    cin >> A >> B >> C;
}