#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    // 1 예외처리
    if(str=="1") {
        printf("NO");
        return 0;
    }

    for(int i=0; i<str.length(); i++) {
        int num1 = 1, num2 = 1;
        for(int j=0; j<=i; j++) {
            num1 *= (str[j]-'0');
        }
        for(int j=i+1; j<str.length(); j++) {
            num2 *= (str[j]-'0');
        }
        //printf("%d %d\n", num1, num2);
        if(num1==num2) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}