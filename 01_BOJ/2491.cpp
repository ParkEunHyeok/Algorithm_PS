#include <iostream>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    
    int n, num, prev_num;
    cin >> n;

    int increasing = 1, decreasing = 1;
    int result = 1;

    cin >> num;
    prev_num = num;

    for(int i=1; i<n; i++) {
        cin >> num;

        if(prev_num < num) {
            increasing++;
            decreasing = 1;
        }
        else if(prev_num==num) {
            increasing++;
            decreasing++;
        }
        else {
            increasing = 1;
            decreasing++;
        }

        prev_num = num;
        result = max(result, max(decreasing, increasing));
    }

    cout << result;
    return 0;
}