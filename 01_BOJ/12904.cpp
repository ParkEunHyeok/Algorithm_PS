#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    
    while(1) {
        if(S.length() == T.length()) {
            if(S==T) cout << 1;
            else cout << 0;
            break;
        }

        char last = T[T.length()-1];
        T.pop_back();
        if(last=='B') reverse(T.begin(), T.end());
    }

    return 0;
}