#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> answer;
bool visited[201][201][201];
int A, B, C;

void bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,0),C));

    while(!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if(visited[a][b][c]) continue;
        visited[a][b][c] = true;
        if(a==0) answer.push_back(c);

        // a -> b
        if(a + b > B) q.push(make_pair(make_pair(a+b-B,B),c));
        else q.push(make_pair(make_pair(0,a+b),c));

        // a -> c
        if(a + c > C) q.push(make_pair(make_pair(a+c-C,b),C));
        else q.push(make_pair(make_pair(0,b),a+c));

        // b -> a
        if(b + a > A) q.push(make_pair(make_pair(A,a+b-A),c));
        else q.push(make_pair(make_pair(a+b,0),c));

        // b -> c
        if(b + c > C) q.push(make_pair(make_pair(a,b+c-C),C));
        else q.push(make_pair(make_pair(a,0),b+c));
        
        // c -> a
        if(c + a > A) q.push(make_pair(make_pair(A,b),c+a-A));
        else q.push(make_pair(make_pair(a+c,b),0));
        
        // c -> b
        if(c + b > B) q.push(make_pair(make_pair(a,B),c+b-B));
        else q.push(make_pair(make_pair(a,b+c),0));
    }
}

int main() {
    cin >> A >> B >> C;

    bfs();
    sort(answer.begin(), answer.end());

    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}