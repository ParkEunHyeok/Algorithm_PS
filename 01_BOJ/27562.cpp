#include <iostream>
using namespace std;

int n, m;
int res = 987654321;
int stall[202];
int conditioner[102][4];

void func(int idx, int cost) {
    if(idx>=m) {
        for(int i=1; i<=100; i++) {
            if(stall[i]>0) return;
        }
        res = min(res, cost);
        return;
    }

    func(idx+1, cost);
    
    int a = conditioner[idx][0];
    int b = conditioner[idx][1];
    int p = conditioner[idx][2];
    int m = conditioner[idx][3];
    
    for(int i=a; i<=b; i++) stall[i] -= p;
    func(idx+1, cost+m);
    for(int i=a; i<=b; i++) stall[i] += p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int s, t, c;
        cin >> s >> t >> c;

        for(int j=s; j<=t; j++) {
            stall[j] += c;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, p, m;
        cin >> a >> b >> p >> m;

        conditioner[i][0] = a;
        conditioner[i][1] = b;
        conditioner[i][2] = p;
        conditioner[i][3] = m;
    }

    func(0, 0);

    cout << res;
    return 0;
}