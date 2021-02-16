#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100002] = {0,};
    cin >> n;

    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum%3!=0) {
        printf("NO");
    }
    else {
        int one = 0;
        int two = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i]/2 > 0) two += arr[i]/2;
            if(arr[i]%2==1) one++;
        }

        while(1) {
            if(one == two) {
                printf("YES");
                break;
            }
            else if(one > two) {
                printf("NO");
                break;
            }
            two--;
            one+=2;
        }
    }

    return 0;
}