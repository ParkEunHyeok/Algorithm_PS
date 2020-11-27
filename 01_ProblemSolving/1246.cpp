#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, arr[1001];
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> arr[i];
    }
    
    int best_price = 0;
    int max_profit = 0;
    for(int i=0; i<m; i++) {
        int price = arr[i];
        int count = 0;
        for(int j=0; j<m; j++) {
            if(arr[j]>=price) count++;
        }

        if(count > n) count = n;

        if(max_profit < (price*count)) {
            best_price = price;
            max_profit = price * count;
        }
        if(max_profit == (price*count)) {
            if(best_price > price) {
                best_price = price;
            }
        }
    }

    printf("%d %d", best_price, max_profit);

    return 0;
}