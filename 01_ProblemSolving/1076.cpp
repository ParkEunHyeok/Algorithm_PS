#include <iostream>
#include <string>

using namespace std;

int main() {
    string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    string str;
    int result[3];
    long long sum = 0;

    for(int i=0; i<3; i++) {
        cin >> str;
        for(int j=0; j<10; j++) {
            if(str==color[j]) result[i] = j;
        }
    }

    sum = (result[0]*10) + result[1];
    for(int i=0; i<result[2]; i++) sum *=10;
    printf("%lld", sum);
    //cout << sum;
    
    return 0;
}