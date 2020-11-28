#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[30000];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for(int i=0; i<n-1; i++) {
        int count = 1;
        while(1) {
            if((i+count)==n) break;
            if(arr[i] > arr[i+count]) count++;
            else break;
        }
        if(max < (count-1)) max = count-1;
    }

    printf("%d", max);
    return 0;
}