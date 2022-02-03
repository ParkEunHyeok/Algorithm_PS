#include <iostream>
using namespace std;

int main() {
    string doc, word;
    getline(cin, doc);
    getline(cin, word);

    int res = 0, idx = 0;
    for(int i=0; i<doc.length(); i++) {
        if(i<idx) i = idx;
        if(doc[i]==word[0]) {
            bool flag = true;
            for(int j=0; j<word.length(); j++) {
                if(doc[i+j]!=word[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                flag = true;
                res++;
                idx = i+word.length();
            }
        }
    }

    cout << res;
    return 0;
}