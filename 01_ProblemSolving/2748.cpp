#include <iostream>

using namespace std;

long long fibonacci(int n) {
    long long fibo[91];
    fibo[0] = 0, fibo[1] = 1;
    for(int i=2; i<=n; i++) {
        fibo[i]= fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}

int main() {
    int number;
    cin >> number;
    cout << fibonacci(number);
    return 0;
}