#include <iostream>
using namespace std;

int main() {
    int t;
    int score = 0;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        string str;
        int weight = 0;

        cin >> str;

        for(int i=0; i<str.length(); i++) {
            if(str[i]=='O') {
                weight++;
                score += weight;
            }
            else {
                weight = 0;
            }
        }

        cout << score << "\n";
        score = 0;
    }

    return 0;
}