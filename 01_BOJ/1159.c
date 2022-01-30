#include <stdio.h>

int main() {
    int alphabet[26] = {0,};
    int n, count=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        char name[61] = {};
        scanf("%s", name);
        alphabet[name[0]-'a'] ++;
    }

    for(int i=0; i<26; i++) {
        if(alphabet[i]>=5) {
            printf("%c", i + 'a');
            count++;
        }
    }
    if(count==0) printf("PREDAJA");

    return 0;
}