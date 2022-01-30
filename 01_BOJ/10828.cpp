#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    stack<int> st;
    string str;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        cin >> str;

        if(str == "push")
        {
            int number;
            scanf("%d", &number);
            st.push(number);
        }
        else if(str == "pop")
        {
            if(st.empty()) printf("-1\n");
            else {
                cout << st.top() << endl;
                st.pop();
            }   
        }
        else if(str == "size")
        {
            cout << st.size() << endl;
        }
        else if(str == "empty")
        {
            if(st.empty()) printf("1\n");
            else printf("0\n");
        }
        else if(str == "top")
        {
            if(st.empty()) printf("-1\n");
            else cout << st.top() << endl;
        }
    }
    return 0;
}