#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, str_length;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str_length;
        string str, target;
        cin >> str >> target;

        int change_white=0, change_black=0;
        for(int i=0; i<str_length; i++) {
            if(str[i]!=target[i]) { // 타겟과 다르다면
                if(str[i]=='W') {
                    change_white++;
                }
                else change_black++;
            }
        }

        cout << max(change_black, change_white) << "\n";
    }
}