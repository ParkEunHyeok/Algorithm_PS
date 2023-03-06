#include <iostream>
using namespace std;

string str;
char block[4][6];
bool visited[4];
bool flag;

void bessie(int num) {
    if(flag) return;
    if(num+1>str.length()) return;

    for(int i=0; i<4; i++) {
        if(visited[i]) continue;

        for(int j=0; j<6; j++) {
            if(block[i][j]==str[num]) {
                if(num+1==str.length()) {
                    cout << "YES\n";
                    flag = true;
                    return;
                }

                visited[i] = true;
                bessie(num+1);
                visited[i] = false;
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    for(int i=0; i<4; i++) {
        cin >> str;
        for(int j=0; j<6; j++) {
            block[i][j] = str[j];
        }
    }

    for(int i=0; i<n; i++) {
        cin >> str;

        flag = false;
        bessie(0);
        if(!flag) cout << "NO\n";
    }

    return 0;
}