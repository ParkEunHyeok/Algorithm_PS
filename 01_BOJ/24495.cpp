#include <iostream>
using namespace std;

int dice[3][4];

int winner(int a, int b) {
    int win = 0, lose = 0;

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(dice[a][i] > dice[b][j]) win++;
            else if(dice[a][i] < dice[b][j]) lose++;
        }
    }

    if(win==lose) return 0;
    else if(win>lose) return 1;
    else return 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        for(int i=0; i<4; i++) cin >> dice[0][i];
        for(int i=0; i<4; i++) cin >> dice[1][i];

        if(winner(0, 1)==2) {
            for(int i=0; i<4; i++) {
                swap(dice[0][i], dice[1][i]);
            }
        }

        bool flag = false;

        for(int i=1; i<=10; i++) {
            for(int j=i; j<=10; j++) {
                for(int k=j; k<=10; k++) {
                    for(int l=k; l<=10; l++) {
                        dice[2][0] = i;
                        dice[2][1] = j;
                        dice[2][2] = k;
                        dice[2][3] = l;

                        if(winner(0, 2)==2 && winner(1, 2)==1) {
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) break;
        }

        if(flag) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}