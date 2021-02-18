#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string str, int skip) {
    int start = 0;
    int end = str.length()-1;

    while(start < end) {
        if(start==skip) start++;
        if(end==skip) end--;

        if(str[start]!=str[end]) {
            return 2;
        }

        start++;
        end--;
    }

    return 1;
}

int discriminant(string str) {
    int start = 0;
    int end = str.length()-1;
    int ans = 0;

    while(start < end) {
        if(ans==2) break;

        if(str[start]!=str[end]) {
            ans = 2;

            if(str[start+1]==str[end]) {
                ans = min(ans, isPalindrome(str, start));
            }

            if(str[start]==str[end-1]) {
                ans = min(ans, isPalindrome(str, end));
            }
            
            return ans;
        }

        start++;
        end--;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    while(n--) {
        string s;
        cin >> s;

        cout << discriminant(s) << "\n";
    }

    return 0;
}