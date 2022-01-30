#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int weight = 10, number = 0;
    int minus = 0;
    int result = 0;
    for(int i=0; i<=str.length(); i++) {
        if(str[i]=='+' || str[i]=='-' || str[i]=='\0') {
            // 기존의 number 먼저 처리
            if(minus) {
                result -= number;
            }
            else {
                result += number;
            }

            // number 갱신
            number = 0;

            // minus 감지
            if(str[i]=='-') {
                minus = 1;
            }
        }
        else {
            number = number*weight + (str[i]-'0');
        }
    }

    cout << result;
    return 0;
}