#include <iostream>
using namespace std;

int main() {
    // 건물의 총 층수, 사는 층 수, 오를 계단의 층 수
    int m, f, n;
    int elevator = 0;
    cin >> m >> f >> n;

    int c = m-1;
    elevator += n/c;
    n -= c * elevator;
    if(n==0) elevator--;
    
    cout << elevator+1;
    return 0;
}