#include <iostream>
#include <cstring>
using namespace std;

int n, d, p, q;
double cache[52][102];
// map : 마을 i, j가 연결되어 있나 여부
// deg : i번째 마음과 연결된 마을의 개수
int map[52][52], deg[52];

// days일째에 here번 마을에 숨어 있다고 가정하고,
// 마지막 날에 q번 마을에 숨어 있을 조건부 학률을 반환한다.
double func(int here, int days) {
    if(days==0) return (here==p ? 1.0 : 0.0);

    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;  

    for(int i=0; i<n; i++) {
        if(map[here][i])
            ret += func(i, days-1) / deg[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    while(c--) {
        for(int i=0; i<=50; i++) {
            for(int j=0; j<=100; j++) {
                cache[i][j] = -1;
            }
            deg[i] = 0;
        }

        cin >> n >> d >> p;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> map[i][j];
                deg[i] += map[i][j];
            }
        }

        cin >> q;
        for(int i=0; i<q; i++) {
            int tmp;
            cin >> tmp;
            cout.precision(8);
            cout << func(tmp, d) << " ";
        }
        cout << "\n";
    }

    return 0;
}