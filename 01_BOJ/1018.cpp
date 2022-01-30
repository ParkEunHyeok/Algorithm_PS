#include <iostream>
using namespace std;

int n, m;

int main() {
    char arr[52][52];
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            arr[i][j] = str[j];
        }
    }

    int result = 100;
    for(int i=0; i+8<=n; i++) {
        for(int j=0; j+8<=m; j++) {
            int cnt=0;
            for(int k=i; k<i+8; k++) {
                for(int l=j; l<j+8; l++) {
                    // 홀수줄 홀수칸
                    if((k-i)%2==0 && (l-j)%2==0) {
                        if(arr[k][l]=='B') cnt++;
                    }
                    // 짝수줄 짝수칸
                    else if((k-i)%2==1 && (l-j)%2==1) {
                        if(arr[k][l]=='B') cnt++;
                    }
                    else {
                        if(arr[k][l]=='W')cnt++;
                    }
                }
            }
            cnt = min(64-cnt, cnt);
            result = min(result, cnt);
        }
    }

    cout << result;
    return 0;
}