#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100001];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int result = 0;
    for(int i=0; i<n; i++) {
        result = max(result, arr[i]*(n-i));
    }   

    printf("%d", result);

    return 0;
}