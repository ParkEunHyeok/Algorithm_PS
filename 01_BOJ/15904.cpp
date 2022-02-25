#include <iostream>
using namespace std;

int main() {
    string s, str;
    int cnt = 0;
    getline(cin, s);

    for(int i=0; i<=s.length(); i++) {
        if(!('A'<=s[i] && s[i]<='Z')) continue;
        if(s[i]=='U' && cnt==0) cnt = 1;
        if(s[i]=='C' && cnt==1) cnt = 2;
        if(s[i]=='P' && cnt==2) cnt = 3;
        if(s[i]=='C' && cnt==3) cnt = 4;
    }

    if(cnt==4) cout << "I love UCPC";
    else cout << "I hate UCPC";
    return 0;
}