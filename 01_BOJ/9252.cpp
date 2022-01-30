#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s1, s2;
    int lcs[1002][1002] = {0,};

    cin >> s1 >> s2;

    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1]==s2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    int maxLen = lcs[s1.length()][s2.length()];
    string result;
    cout << maxLen << "\n";

    int i = s1.length(), j = s2.length();
    stack<int> s;

    while(lcs[i][j] != 0) {
        if(lcs[i][j] == lcs[i][j-1]) {
            j--;
        }
        else if(lcs[i][j] == lcs[i-1][j]) {
            i--;
        }
        else if(lcs[i][j]-1 == lcs[i-1][j-1]) {
            i--, j--;
            s.push(i);
        }
    }

    while(!s.empty()) {
        cout << s1[s.top()];
        s.pop();
    }

    return 0;
}