#include <iostream>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    char arr[52][52] = {0,};
    bool checked[52][52] = {0,};
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            arr[i][j] = str[j];
        }
    }

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) {
            if((str[j]) == arr[i][j]) {
                checked[i][j] = false;
            }
            else checked[i][j] = true;
        }
    }

    int cnt = 0;

    for(int i=0; i<=n-3; i++) {
        for(int j=0; j<=m-3; j++) {
            if(checked[i][j]) {
                cnt++;
                for(int k=i; k<i+3; k++) {
                    for(int l=j; l<j+3; l++) {
                        if(checked[k][l]) checked[k][l] = false;
                        else checked[k][l] = true;
                    }
                }
            } 
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(checked[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;
    return 0;
}