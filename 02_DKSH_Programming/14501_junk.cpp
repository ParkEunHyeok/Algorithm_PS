#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int day[15], pay[15];
    for(int i=0; i<n; i++) {
        cin >> day[i] >> pay[i];
    }

    int cancel = 0, max = 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i<=n; i++) {
            int loan = 0;
            for(int j=0; j<n; j++) {
                if(j==(i-1)) {
                    cancel--;
                    continue;
                }
                if(n-j-day[j]<0) continue;
                if(cancel>0) {
                    cancel--;
                    continue;
                } else { 
                    loan += pay[j];
                    cancel = day[j] - 1;
                }
            }
            if(max < loan) max = loan;
        }
    }
    
    printf("%d", max);
    return 0;
}