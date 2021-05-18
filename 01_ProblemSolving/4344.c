#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int score = 0;
        float student = 0;
        int arr[1002];
        float n;
        
        scanf("%f", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
            score += arr[i];
        }

        float avg = score / n;

        for(int i=0; i<n; i++) {
            if(avg < arr[i]) {
                student++;
            }
        }

        float result = (100*student)/n;

        printf("%.3f", result);
        printf("%%\n");
    }

    return 0;
}