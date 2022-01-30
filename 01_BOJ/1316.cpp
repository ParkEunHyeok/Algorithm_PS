#include <iostream>
using namespace std;

int main() {
    int n;
    int result = 0;
    cin >> n;

    for(int i=0; i<n; i++) {
        int arr[30] = {0,};
        bool flag = true;
        int prev = 0;

        string str;
        cin >> str;

        for(int j=0; j<str.length(); j++) {
            int cur = str[j] - 'a';

            if(prev==cur) {
                arr[cur]++;
                prev = cur;
                continue;
            }

            if(arr[cur]) {
                flag = false;
                break;
            }

            arr[cur]++;
            prev = cur;
        }

        if(flag) result++;
    }

    cout << result;
    return 0;
}