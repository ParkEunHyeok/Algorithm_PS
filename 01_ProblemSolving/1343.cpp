#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    // 모두 AAAA, BB로 덮을 수 있는지 조사함.
    int cnt=0;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='X') {
            cnt++;
        }
        else {
            if(cnt%2==1) {
                printf("-1");
                return 0;
            } else cnt = 0; 
        }
    }
    if(cnt%2==1) {
        printf("-1");
        return 0;
    }

    // 덮을 수 있다면 AAAA, BB로 덮기
    cnt = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='X') {
            cnt++;
        }
        else {
            while(cnt-4>=0) {
                printf("AAAA");
                cnt-=4;
            }
            while(cnt-2>=0) {
                printf("BB");
                cnt-=2;
            }
            if(cnt==0) {
                printf(".");
            }
        }
    }
    while(cnt-4>=0) {
        printf("AAAA");
        cnt-=4;
    }
    while(cnt-2>=0) {
        printf("BB");
        cnt-=2;
    }

    return 0;
}