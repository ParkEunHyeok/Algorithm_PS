#include <iostream>
using namespace std;

int arr[1002];

void hansu(int num) {
    int hund = num / 100;
    int ten = (num % 100) / 10;
    int one = num % 10;

    if((ten-hund)==(one-ten)) arr[num] = 1;
}

int main() {
    int result = 99;

    int n;
    cin >> n;

    if(n<=99) {
        cout << n;
    }
    else {
        for(int i=100; i<=n; i++) {
            hansu(i);
        }
        for(int i=100; i<=n; i++) {
            if(arr[i]==1) result++;
        }

        cout << result;
    }

    return 0;
}