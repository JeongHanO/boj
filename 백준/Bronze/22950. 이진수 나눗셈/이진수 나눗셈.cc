#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    stack<int> s;

    int a;
    for (int i = 0; i < n; i++) {
        scanf("%1d", &a);
        s.push(a);
    }

    int k; cin >> k;
    
    for (int i = 0; i < k; i++) {
        if (s.empty()) break;
        
        int tmp = s.top();
        s.pop();

        if (tmp) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}