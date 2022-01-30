#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if(a.size()==b.size()) {
        return a<b;
    }
    else return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;

    vector<string> v;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    string prev;
    for(int i=0; i<n; i++) {
        if(v[i]==prev) continue;
        cout << v[i] << "\n";
        prev = v[i];
    }

    return 0;
}