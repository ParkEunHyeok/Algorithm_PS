#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int countP = 0;

    if(str=="P") {
        cout << "PPAP";
        return 0;
    }

    for(int i=0; i<str.length(); i++) {
        if(str[i]=='P') {
            countP++;
            continue;
        }

        if(countP>=2 && str[i+1]=='P') {
            countP--;
            i++;
        }
        else {
            cout << "NP";
            return 0;
        }
    }

    if(countP==1) cout << "PPAP";
    else cout << "NP";

    return 0;
}