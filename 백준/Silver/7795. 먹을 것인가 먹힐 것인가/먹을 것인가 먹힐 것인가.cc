#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        for (int j = 0; j < m; j++)
            cin >> b[j];
        sort(b.begin(), b.end());

        int ans = 0;

        for (auto &j : a)
        {
            int left = 0;
            int right = m;
            while (left + 1 < right)
            {
                int mid = (left + right) / 2;
                if (j > b[mid])
                    left = mid;
                else
                    right = mid;
            }
            ans += left;
            if (j > b[left])
                ans++;
        }
        cout << ans << endl;
    }
}
