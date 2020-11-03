#include <stdio.h>

int main() {
    int n;
    int my_stick = 64;
    scanf("%d", &n);

    int count = 1;
    while(1) {
        if(n < my_stick) {
            my_stick /= 2;
        }
    }
}