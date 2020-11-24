#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stick = 64, count=1;
    while(1) {
        if(stick < n) break;
        else if(stick == n) {
            printf("1");
            return 0;
        }
        stick /= 2;
    }
    int plus = stick;
    while(1) {
        plus /= 2;
        if((stick+plus)>n) {
            continue;
        } else {
            stick += plus;
            count++;
        }

        if(stick == n) {
            break;
        }
    }
    printf("%d", count);
    return 0;
}