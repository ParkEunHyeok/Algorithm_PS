#include <iostream>
#include <string>
using namespace std;

int n, m;
int arr[52][52];

int square() {
    int result = 1;

    int ran = min(n,m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=1; k<ran; k++) {
                int cur = arr[i][j];
                if(i+k<n && j+k<m) {
                    if(cur==arr[i+k][j+k] && cur==arr[i][j+k] && cur==arr[i+k][j]) {
                        result = max(result, k+1);
                    }
                }
            }
        }
    }

    return result * result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            arr[i][j] = str[j]-'0';
        }
    }

    cout << square();
    return 0;
}