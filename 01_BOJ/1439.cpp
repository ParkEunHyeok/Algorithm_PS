#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int prev = str[0]-'0';
    int count = 0;
    for(int i=1; i<str.length(); i++) {
        if(prev==str[i]-'0') continue;
        else {
            count++;
            prev = (prev+1)%2;
        }
    }
    if(count==0) printf("0");
    else printf("%d", ((count-1)/2)+1);
    return 0;
}