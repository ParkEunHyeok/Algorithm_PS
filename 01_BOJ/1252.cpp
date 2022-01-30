#include <iostream>
#include <string>

using namespace std;

int main() {
    string one, two;
    cin >> one >> two;

    // 앞에 붙은 0 지워주기
    int count = 0;
    for(int i=0; i<one.size(); i++) {
        if(one[i]=='0') count++;
        else break;
    }
    one.erase(0, count);
    count = 0;
    for(int i=0; i<two.size(); i++) {
        if(two[i]=='0') count++;
        else break;
    }
    two.erase(0, count);

    // 만약 둘 다 NULL이 된다면 0출력, 종료
    if(one.empty() && two.empty()) {
        printf("0");
        return 0;
    }

    // one이 더 길도록 스왑, one-two의 차를 구해서 그만큼 two에 0을 붙이기
    if(one.size() < two.size()) one.swap(two);
    int equal_len = one.size() - two.size();
    int arr1[82], arr2[82];
    // arr1, arr2 배열에 길이를 같게 해서 옮기기
    for(int i=0; i<equal_len; i++) {
        arr2[i] = 0;
    }
    for(int i=0; i<one.size(); i++) {
        arr1[i] = one[i]-'0';
    }
    for(int i=0; i<two.size(); i++) {
        arr2[i + equal_len] = two[i] - '0';
    }

    // 가산기처럼 일의 자리부터 연산
    int result[85];
    int carry = 0;
    for(int i=0; i<one.size(); i++) {
        int sum = arr1[one.size()-i-1] + arr2[one.size()-i-1] + carry;
        if(sum >= 2) {
            carry = 1;
            sum = sum - 2;
        } else {
            carry = 0;
        }
        result[one.size()-i] = sum;
    }

    // 만약 맨 앞자리 받아올림을 받는다면 1출력
    if(carry==1) printf("1");
    // result 출력
    for(int i=1; i<=one.size(); i++) {
        printf("%d", result[i]);
    }

    return 0;
}