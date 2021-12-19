#include <iostream>
using namespace std;

int main() {
    long long n, res = 0;
    cin >> n;

    long long i = 1;
    while(1) {
        res += i;
        if(n < res) {
            cout << i-1;
            break;
        }
        i++;
    }

    return 0;
}