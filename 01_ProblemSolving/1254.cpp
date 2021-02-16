#include <iostream>
#include <string>
using namespace std;

string str;
int len;

int addi() {
    int result = 0;

    for(int i=0; i<len-1; i++) {
        if(str[i]==str[len-1]) {
            int start = i;
            int end = len-1;
            for(int j=0; j<(len-i)/2; j++) {
                if(str[start]==str[end]) {
                    start++;
                    end--;
                }
                else {
                    result++;
                    break;
                }
            }

            if(start>=end) break;
        }
        else result++;
    }

    return result;
}

int main() {
    cin >> str;
    len = str.length();

    cout << len + addi();
    return 0;
}