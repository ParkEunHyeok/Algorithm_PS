#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string first_str;
    cin >> first_str;
    string result = first_str;

    for(int i=1; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j < str.length(); j++) {
            if(str[j]!=result[j])
                result[j] = '?';
        }
    }
    cout << result;
    return 0;
}