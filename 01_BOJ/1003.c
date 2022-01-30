#include <stdio.h>

int main() {
    int zero_count[41] = {1,0};
    int one_count[41] = {0,1};
    for(int i=2; i<=40; i++) {
        zero_count[i] = zero_count[i-2] + zero_count[i-1];
        one_count[i] = one_count[i-2] + one_count[i-1];
    }

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int number;
        scanf("%d", &number);
        printf("%d %d\n", zero_count[number], one_count[number]);
    }
    return 0;
}