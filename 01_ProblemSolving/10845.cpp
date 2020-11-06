#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        if(str == "push") {
            int number;
            scanf("%d", &number);
            q.push(number);
        }
        else if(str == "pop") {
            if(q.empty()) printf("-1\n");
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size") {
            cout << q.size() << '\n';
        }
        else if(str == "empty") {
            if(q.empty()) printf("1\n");
            else printf("0\n");
        }
        else if(str == "front") {
            if(q.empty()) printf("-1\n");
            else cout << q.front() << '\n';
        }
        else if(str == "back") {
            if(q.empty()) printf("-1\n");
            else cout << q.back() << '\n';
        }
    }
    return 0;
}