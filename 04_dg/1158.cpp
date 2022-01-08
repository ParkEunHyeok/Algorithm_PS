#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    int cnt = 0, poped=0;
    queue<int> q;

    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        q.push(i);
    }

    cout << "<";
    while(1) {
        cnt++;

        if(cnt==k) {
            cnt = 0;
            poped++;
            printf("%d, ", q.front());
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }

        if(poped==n-1) {
            printf("%d>", q.front());
            break;
        }
    }

    return 0;
}