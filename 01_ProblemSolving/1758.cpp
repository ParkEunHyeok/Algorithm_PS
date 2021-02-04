#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[100002];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n, greater<int>());

    int count = 0;
    long long sum_money = 0;
    for(int i=0; i<n; i++) {
        count++;
        int money = arr[i]-(count-1);
        if(money > 0) sum_money += money;
    }

    cout << sum_money;
    return 0;
}