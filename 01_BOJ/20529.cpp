#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;   // 테스트 케이스 개수, 인자의 개수
    cin >> t;
    for(int m=0; m<t; m++) {
        cin >> n;
        vector<string> v(n);
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        
        int result = 1004;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    string str1 = v[i];
                    string str2 = v[j];
                    string str3 = v[k];
                    int sum = 0;
                    for(int l=0;l<4; l++) {
                        if(str1[l]==str2[l] && str2[l]==str3[l] && str3[l]==str1[l]) {
                            continue;
                        }
                        else sum += 2;
                    }
                    result = min(sum, result);

                    if(result==0) break;
                }
                if(result==0) break;
            }
            if(result==0) break;
        }

        v.clear();
        cout << result << "\n";
    }

    return 0;
}