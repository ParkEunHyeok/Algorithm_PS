#include <iostream>
using namespace std;

int main() {
    int e, s, m;
    int a=1, b=1, c=1;
    int result = 1;
    cin >> e >> s >> m;

    while(1) {
        if(a==e && b==s && c==m) break;
        result++;   
        a++, b++, c++;
        if(a>15) a = 1;
        if(b>28) b = 1;
        if(c>19) c = 1;
    }

    cout << result;
    return 0;
}