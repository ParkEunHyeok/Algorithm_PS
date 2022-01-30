#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string str;
        int n;
        cin >> str >> n;
        deque<int> dq;
        string inputs;
        cin >> inputs;
        for(int i=0; i<inputs.length(); i++) {
            if(inputs[i]=='[' || inputs[i]==']' || inputs[i]==',') {
                continue;
            }
            else {
                int weight = 10;
                int j = i;
                int number = 0;
                while(inputs[j]!='[' && inputs[j]!=']' && inputs[j]!=',') {
                    number = (number*weight) + (inputs[j]-'0');
                    j++;
                    i++;
                }
                dq.push_back(number);
            }
        }

        bool p = true;  // true:순방향, false:역방향
        bool flag = true;   // true:정상, false:error 출력
        int front_index = 0;    // 정방향 인덱스
        int back_index = n-1; // 역방향 인덱스
        int dqsize = n;
        for(int i=0; i<str.length(); i++) {
            if(str[i]=='R') {   // 뒤집기
                p = !p;
            }
            else {  // 맨 앞 글자 pop
                if(dqsize==0) {
                    flag = false;
                    break;
                }
                if(p) { // 정방향
                    dqsize--;
                    front_index++;
                }
                else {  // 역방향
                    dqsize--;
                    back_index--;
                }
            }
        }

        if(flag) {
            cout << "[";
            if(p) {
                for(int i=front_index; i<=back_index; i++) {
                    cout << dq[i];
                    if(i!=back_index) cout << ",";
                }
            }
            else {
                for(int i=back_index; i>=front_index; i--) {
                    cout << dq[i];
                    if(i!=front_index) cout << ",";
                }
            }
            cout << "]\n";
        }
        else cout << "error\n";
    }
    return 0;
}