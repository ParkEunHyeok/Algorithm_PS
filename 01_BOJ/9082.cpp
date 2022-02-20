#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        int n;
        string str1, str2;
        cin >> n >> str1 >> str2;
        vector<int> nearby(n);
        vector<char> mine(n);

        for(int i=0; i<n; i++) {
            nearby[i] = str1[i]-'0';
            mine[i] = str2[i];
        }

        // 확정할 수 있는 것 확정
        for(int i=0; i<n; i++) {
            if(nearby[i]==2) {
                if(i==0) {
                    nearby[i] = 0;
                    mine[0] = '*';
                    mine[1] = '*';
                }
                else if(i==n-1) {
                    nearby[i] = 0;
                    mine[n-1] = '*';
                    mine[n-2] = '*';
                }
            }
            if(nearby[i]==3) {
                nearby[i] = 0;
                mine[i-1] = '*';
                mine[i] = '*';
                mine[i+1] = '*';
            }
        }

        if(nearby[0]==1) {
            if(mine[0]=='.') mine[1] = '*';
            if(mine[1]=='.') mine[0] = '*';
            if(mine[0]=='*') mine[1] = '.';
            if(mine[1]=='*') mine[0] = '.';
        }

        if(nearby[n-1]==1) {
            if(mine[n-1]=='.') mine[n-2] = '*';
            if(mine[n-2]=='.') mine[n-1] = '*';
            if(mine[n-1]=='*') mine[n-2] = '.';
            if(mine[n-2]=='*') mine[n-1] = '.';
        }

        while(1) {
            for(int i=0; i<n; i++) {
                if(nearby[i]==0) {
                    if(i==0) {
                        if(mine[0]=='#') mine[0] = '.';
                        if(mine[1]=='#') mine[1] = '.';
                    }
                    else if(i==n-1) {
                        if(mine[n-1]=='#') mine[n-1] = '.';
                        if(mine[n-2]=='#') mine[n-2] = '.';
                    }
                    else {
                        if(mine[i-1]=='#') mine[i-1] = '.';
                        if(mine[i]=='#') mine[i] = '.';
                        if(mine[i+1]=='#') mine[i+1] = '.';
                    }
                }
            }

            for(int i=1; i<n-1; i++) {
                
            }
        }
    }

    return 0;
}