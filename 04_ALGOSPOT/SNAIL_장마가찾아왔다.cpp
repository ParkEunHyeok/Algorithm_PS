#include <iostream>
#include <cstring>
using namespace std;

int n, m;
double cache[1002][2002];

// 달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때,
// m일 전까지 n미터를 기어올라갈 수 있는 경우의 수
double climb(int days, int climbed) {
    if(days==m) return climbed>=n ? 1 : 0;

    double& ret = cache[days][climbed];
    if(ret!=-1) return ret;

    return ret = 0.25*climb(days+1, climbed+1)
                +0.75*climb(days+1, climbed+2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        cin >> n >> m;
        
        for(int i=0; i<=1000; i++) {
            for(int j=0; j<=2001; j++) {
                cache[i][j] = -1;
            }
        }

        cout.precision(10);
        cout << climb(0,0) << "\n";
    }

    return 0;
}