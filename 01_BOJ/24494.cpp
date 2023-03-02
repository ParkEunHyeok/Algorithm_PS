#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char correct[3][3], guess[3][3];
    int correct_freq[26] = {0,};
    int guess_freq[26] = {0,};
    int green = 0, yellow = 0;

    for(int i=0; i<3; i++) {
        string str;
        cin >> str;
        for(int j=0; j<3; j++) {
            correct[i][j] = str[j];
            correct_freq[str[j]-'A']++;
        }
    }
    for(int i=0; i<3; i++) {
        string str;
        cin >> str;
        for(int j=0; j<3; j++) {
            guess[i][j] = str[j];
            guess_freq[str[j]-'A']++;
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(correct[i][j]==guess[i][j]) {
                green++;
                correct_freq[correct[i][j]-'A']--;
                guess_freq[guess[i][j]-'A']--;
            }
        }
    }

    for(int i=0; i<26; i++) {
        yellow += min(correct_freq[i], guess_freq[i]);
    }

    cout << green << "\n" << yellow;
    return 0;
}