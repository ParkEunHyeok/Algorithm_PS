#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[1002];
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int result = arr[0];
    int prev = arr[0];
    for(int i=1; i<n; i++) {
        prev += arr[i];
        result += prev;
    }

    cout << result;
    return 0;
}