#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    int lcs[1002][1002] = {0,};
    cin >> s1 >> s2;

    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1]!=s2[j-1]) lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            else lcs[i][j] = lcs[i-1][j-1] + 1;
        }
    }

    cout << lcs[s1.length()][s2.length()];
    return 0;
}