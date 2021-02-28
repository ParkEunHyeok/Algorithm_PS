#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int max_len = 0;
int len = 0;
int number = 10;
int alphabet[26];
vector<string> v;

long long get_result() {
    long long sum = 0;

    for(int i=0; i<26; i++) {
        number--;
        sum += number * alphabet[i];
    }

    return sum;
}

void wordmath() {
    for(int i=0; i<n; i++) {
        string str = v[i];
        int weight = pow(10, str.length()-1);

        for(int j=0; j<str.length(); j++) {
            alphabet[str[j]-'A'] += weight;
            weight /= 10;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;    
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        int a = str.length();
        len = max(len, a);
    }
    
    wordmath();
    sort(alphabet, alphabet+26, greater<int>());
    cout << get_result();

    return 0;
}