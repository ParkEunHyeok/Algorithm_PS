#include <iostream>
#include <stack>

using namespace std;

int main() {
    int fibo[50];
    fibo[0] = 0;
    fibo[1] = 1;
    int current = 2;
    while(1) {
        fibo[current] = fibo[current-1] + fibo[current-2];
        if(fibo[current] > 1000000000) break;
        else current++;
    }

    int t;
    stack<int> s;
    cin >> t;
    for(int i=0; i<t; i++) {
        int num;
        cin >> num;
        
        int max_index = 45;
        for(int j=1; j<=45; j++) {
            if(fibo[j] <= num) max_index = j;
            else break;
        }

        for(int j=max_index; j>0; j--) {
            if((num-fibo[j])>0) {
                num -= fibo[j];
                s.push(fibo[j]);
            }
            else if((num-fibo[j])==0) {
                s.push(fibo[j]);
                break;
            }
            else continue;
        }

        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        printf("\n");
    }

    return 0;
}