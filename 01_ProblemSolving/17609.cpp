#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;
        int len = str.length();

        int start = 0;
        int end = len-1;
        int ans = 0;

        for(int i=0; i<(len/2); i++) {
            if(ans==2) break;
            
            if(str[start]==str[end]) {
                start++;
                end--;
            }
            else {
                ans++;
                start++;
                end--;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}