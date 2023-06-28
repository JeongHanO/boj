#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int main() {
    fast;
    string a;
    while (1) {
        getline(cin, a);
        if (cin.eof()) break;
        cout << a << "\n";
    }
    return 0;
}