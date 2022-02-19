#include <iostream>
using namespace std;

string reverse(string::iterator& it) {
    char head = *it;
    ++it;

    if(head=='b' || head=='w')
        return string(1, head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 각각 위와 아래 조각들의 위치를 바꾼다.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        string str;
        cin >> str;

        string::iterator iter = str.begin();
        cout << reverse(iter) << "\n";
    }

    return 0;
}