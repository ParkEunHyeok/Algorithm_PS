#include <iostream>
#include <string>

using namespace std;

int main() {
    while(1) {
        string str;
        cin >> str;
        if(str=="0") break;

        int checked = 0;
        for(int i=0; i<str.length()/2; i++) {
            if(str[i]!=str[str.length()-1-i]) {
                printf("no\n");
                checked = 1;
                break;
            }
        }
        if(checked==0) printf("yes\n");
    }
    return 0;
}