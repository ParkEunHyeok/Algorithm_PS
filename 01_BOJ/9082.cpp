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

        for(int i=0; i<n; i++) {
            if(nearby[i]==0) {
                if(i==0) {
                    mine[0] = '.';
                    mine[1] = '.';
                }
                else if(i==n-1) {
                    mine[n-1] = '.';
                    mine[n-2] = '.';
                }
                else {
                    mine[i-1] = '.';
                    mine[i] = '.';
                    mine[i+1] = '.';
                }
            }
            if(nearby[i]==2) {
                if(i==0) {
                    mine[0] = '*';
                    mine[1] = '*';
                }
                else if(i==n-1) {
                    mine[n-1] = '*';
                    mine[n-2] = '*';
                }
            }
            if(nearby[i]==3) {
                mine[i-1] = '*';
                mine[i] = '*';
                mine[i+1] = '*';
            }
        }

        while(1) {
            for(int i=0; i<n; i++) {
                if(i==0) {
                    if(nearby[0]!=1) continue;
                    if(mine[0]=='*') mine[1] = '.';
                    else if(mine[0]=='.') mine[1] = '*';
                    else if(mine[1]=='*') mine[0] = '.';
                    else if(mine[1]=='.') mine[0] = '*';
                }
                else if(i==n-1) {
                    if(nearby[n-1]!=1) continue;
                    if(mine[n-1]=='*') mine[n-2] = '.';
                    else if(mine[n-2]=='*') mine[n-1] = '.';
                }
                else {
                    int a = 0, b = 0;
                    for(int j=i-1; j<=i+1; j++) {
                        if(mine[j]=='*') a++;
                        if(mine[j]=='b') b++;
                    }
                    if(nearby[i]==1) {
                        if(a==1) {
                            for(int j=i-1; j<=i+1; j++) {
                                if(mine[j]!='*') mine[j] = '.';
                            }
                        }
                        if(b==2) {
                            for(int j=i-1; j<=i+1; j++) {
                                if(mine[j]!='.') mine[j] = '*';
                            }
                        }
                    }
                    if(nearby[i]==2) {
                        if(a==2) {
                            for(int j=i-1; j<=i+1; j++) {
                                if(mine[j]!='*') mine[j] = '.';
                            }
                        }
                        if(b==1) {
                            for(int j=i-1; j<=i+1; j++) {
                                if(mine[j]!='.') mine[j] = '*';
                            }
                        }
                    }
                }
            }

            int cnt = 0;
            bool flag = true;
            for(int i=0; i<n; i++) {
                if(mine[i]=='*') cnt++;
                if(mine[i]=='#') {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << cnt << "\n";
                break;
            }
        }
    }

    return 0;
}