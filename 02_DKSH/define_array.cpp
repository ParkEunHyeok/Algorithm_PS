#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3,4, 5, 5,6, 4, 4 ,5 ,4 ,2, 2,4};

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return 0;
}