#include <iostream>
using namespace std;

int main() {
    int n, res=0;
    int start=1, end=9, w=1;
    scanf("%d", &n);

    while(1) {
        if(n<end) {
            res += w*(n-start+1);
            break;
        }
        res += w*(end-start+1);
        w++;
        start *= 10;
        end = (start*10)-1;
    }

    cout << res;
    return 0;
}