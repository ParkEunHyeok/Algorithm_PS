#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result = 0;
    int arr[100001];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    
    int end = n-1;
    for(int i=0; i<=end; i++) {
        if(i%3==2) continue;
        result += arr[i];
    }

    cout << result;
    return 0;
}