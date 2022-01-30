#include <iostream>
using namespace std;

int arr[1002];
int large=0;
int le=9999;
int ri=0;

int leftSum() {
    int sum = 0;
    int amount = 0;
    for(int i=le; i<large; i++) {
        amount = max(amount, arr[i]);
        sum += amount;
    }

    return sum;
}

int rightSum() {
    int sum = 0;
    int amount = 0;
    for(int i=ri; i>large; i--) {
        amount = max(amount, arr[i]);
        sum += amount;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int loc, height;
        cin >> loc >> height;
        arr[loc] = height;

        if(height > arr[large]) {
            large = loc;
        }
        le = min(le, loc);
        ri = max(ri, loc);
    }

    int answer = leftSum()+arr[large]+rightSum();
    cout << answer;
    return 0;
}