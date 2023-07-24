#include <iostream>
using namespace std;
int w[302], t[302],a[302];
int n, h;
int main() {
    for (int i = 1; i <= 301; i++)
    {
        a[i] = i;
        t[i] = t[i - 1] + a[i];
    }
    for (int i = 1; i <= 300; i++)
    {
        for (int k = 1; k <= i; k++)
            w[i] += k * t[k + 1];
    }
    cin >> h;
    while (h--)
    {
        cin >> n;
        cout << w[n] << '\n';
    }
}