#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    queue<long long> q;
    long long descend[1000001];
    int cnt=10;

    cin >> n;
    if(0<=n && n<=10) {
        cout << n;
        return 0;
    }

    for(int i=1; i<=9; i++) {
        q.push(i);
        descend[i] = i;
    }
    
    while(cnt<=n && q.empty()==false) {
        long long num = q.front();
        q.pop();

        int one = num % 10;
        for(int i=0; i<one; i++) {
            q.push(num*10+i);
            descend[cnt] = num*10+i;
            cnt++;
        }
    }

    if(cnt>=n && descend[n]!=0) cout << descend[n];
    else cout << -1;
    return 0;
}