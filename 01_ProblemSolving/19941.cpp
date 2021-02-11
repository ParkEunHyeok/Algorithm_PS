#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;   // 식탁의 길이, 햄버거를 선택할 수 있는 거리
    string str;
    cin >> n >> k;
    cin >> str;

    int can_eat = 0;

    for(int i=0; i<n; i++) {
        if(str[i]=='P') {
            bool flag = false;
            for(int j=k; j>=1; j--) {
                if(i-j<0) continue;
                if(str[i-j]=='H') {
                    can_eat++;
                    str[i-j] = 'N';
                    flag = true;
                    break;
                }
            }

            if(flag) continue;

            for(int j=1; j<=k; j++) {
                if((i+j) > (n-1)) continue;
                if(str[i+j]=='H') {
                    can_eat++;
                    str[i+j] = 'N';
                    break;
                }
            }
        }
    }

    cout << can_eat;
    return 0;
}