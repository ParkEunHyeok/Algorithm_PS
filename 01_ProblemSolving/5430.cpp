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
        if(inputs=="[]") {
            cout << "error\n";
            continue;
        }
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

        bool p = true;
        bool flag = true;
        for(int i=0; i<str.length(); i++) {
            if(str[i]=='R') {   // 뒤집기
                p = !p;
            }
            else {  //삭제
                if(dq.empty()) {
                    flag = false;
                    cout << "error" << "\n";
                }
                
                if(p) {   // 정방향
                    dq.pop_front();
                }
                else  { // 역방향
                    dq.pop_back();
                }
            }
        }

        if(flag) {
            cout << "[";
            if(p) { // 정방향
                for(int i=0; i<(int)dq.size()-1; i++) {
                    cout << dq[i] << ",";
                }
                cout << dq[(int)dq.size()-1] << "]" << "\n";
            }
            else {  // 역방향
                for(int i=(int)dq.size()-1; i>0; i--) {
                    cout << dq[i] << ",";
                }
                cout << dq[0] << "]" << "\n";
            }
        }
        else continue;
    }

    return 0;
}