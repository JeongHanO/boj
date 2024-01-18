#include <vector>
#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    int a = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > a) {
            a = v[i];
        }
        else {
            ans++;
            a = v[i];
        }
    }

    if (v[0] > v[n - 1]) {
        cout << ans;
    }
    else {
        cout << ans + 1;
    }
    return 0;
}