#include <bits/stdc++.h>
using namespace std;
void print0(int t) {
    for (int i = 0; i < t; i++) {
        cout << "0";
    }
}
int main() {
    string a, b;
    char o;
    cin >> a >> o >> b;
    int a0 = a.size() - 1;
    int b0 = b.size() - 1;
    if (o == '+') {
        if (a0 == b0) {
            cout << "2";
            print0(a0);
        } else {
            cout << "1";
            int big = max(a0, b0);
            int small = min(a0, b0);
            print0(big - small - 1);
            cout << "1";
            print0(small);
        }
    }
    if (o == '*') {
        cout << "1";
        print0(a0 + b0);
    }
}