#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    list<char> li;
    list<char>::iterator cursor;
    string str;
    int n;
    cin >> str >> n;
    
    for(int i=0; i<str.length(); i++) {
        li.push_back(str[i]);
    }
    cursor = li.end();

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        if(str=="L") {  // 커서 왼쪽 한 칸 이동
            if(cursor!=li.begin()) {
                cursor--;
            }
        }
        else if(str=="D") { // 커서 오른쪽 한칸 이동
            if(cursor!=li.end()) {
                cursor++;
            }
        }
        else if(str=="B") { // 커서 왼쪽 문자 삭제
            if(cursor!=li.begin()) {
                cursor--;
                cursor = li.erase(cursor);
            }
        }
        else if(str=="P") { // 문자 추가
            char text;
            cin >> text;
            li.insert(cursor, text);
        }
    }

    for(char text : li) cout << text;
    return 0;
}