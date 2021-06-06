#include <iostream>
#include <stack>
using namespace std;

int n, cnt;

stack<int> one,two,three;

void hanoi(int n) {
    
}

int main() {
    cin >> n;

    for(int i=n; i>0; i++) {
        one.push(i);
    }

    hanoi(n);
}