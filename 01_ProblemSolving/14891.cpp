#include <iostream>
using namespace std;

int gear[4][8];

void cw(int idx) {
    int tmp = gear[idx][7];
    for(int i=6; i>=0; i--) {
        gear[idx][i+1] = gear[idx][i];
    }
    gear[idx][0] = tmp;
}

void countercw(int idx) {
    int tmp = gear[idx][0];
    for(int i=0; i<7; i++) {
        gear[idx][i] = gear[idx][i+1];
    }
    gear[idx][7] = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    for(int i=0; i<4; i++) {
        cin >> str;
        for(int j=0; j<8; j++) {
            gear[i][j] = str[j]-'0';
        }
    }

    int n, t, dir;
    cin >> n;

    while(n--) {
        cin >> t >> dir;
        t--;
        int state[4]={0,};
        state[t] = dir;

        // 왼쪽으로 회전
        for(int i=t-1; i>=0; i--) {
            if(gear[i+1][6]!=gear[i][2]) {
                state[i] = -state[i+1];
            } else break;
        }
        // 오른쪽으로 회전
        for(int i=t+1; i<4; i++) {
            if(gear[i-1][2]!=gear[i][6]) {
                state[i] = -state[i-1];
            } else break;
        }

        for(int i=0; i<4; i++) {
            if(state[i]==1) cw(i);
            else if(state[i]==-1) countercw(i);
        }
    }

    int res=0;
    for(int i=0; i<4; i++) {
        if(gear[i][0]==1) res += 1<<i;
    }

    cout << res;
    return 0;
}