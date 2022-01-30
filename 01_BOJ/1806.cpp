#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s;
    int temp;
    vector<int> psum;

    cin >> n >> s;
    cin >> temp;
    psum.push_back(temp);
    for(int i=1; i<n; i++) {
        cin >> temp;
        psum.push_back(temp+psum[i-1]);
    }

    if(psum[n-1] < s) {
        cout << 0;
        return 0;
    }

    int left=0, right=0;
    int prefixSum = psum[0];
    int len = 1;
    int result = 110000;
    bool flag = false;

    while(left <= right && right < n) {
        while(right < n && prefixSum < s) {
            right++;

            int left_sum = 0;
            if(left==0) {
                prefixSum = psum[right];
            }
            else {
                prefixSum = psum[right] - psum[left-1];
            }

            len++;
            if(right==n-1) flag = true;
        }

        result = min(result, len);

        while(left <= right) {
            left++;
            len--;
            prefixSum = psum[right] - psum[left-1];
            if(prefixSum < s) break;
            result = min(result, len);
        }

        if(flag) break;
    }

    cout << result;
    return 0;
}