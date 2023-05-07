#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> visited(100001, false);
    vector<int> cnt(100001, 0);
    queue<int> q;

    q.push(n);
    cnt[n] = 0;

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        visited[a] = true;
        if (a == k)
        {
            // for (int i = 0; i < visited.size(); i++)
            // {
            //     cout << "i = " << i << " / cnt[i] = " << cnt[i] << endl;
            // }
            cout << cnt[a] << endl;
            break;
        }
        // if (a - 1 >= n && !visited[a - 1])
        if (a - 1 >= 0 && !visited[a - 1])
        {
            // cout << "a -1 = " << a - 1 << endl;
            visited[a - 1] = true;
            cnt[a - 1] = cnt[a] + 1;
            q.push(a - 1);
        }
        // /if (a + 1 <= k && !visited[a + 1])
        if (a + 1 < 100001 && !visited[a + 1])
        {
            // cout << "a + 1 = " << a + 1 << endl;
            visited[a + 1] = true;
            cnt[a + 1] = cnt[a] + 1;
            q.push(a + 1);
        }
        if (2 * a < 100001 && !visited[2 * a])
            if (!visited[2 * a])
            {
                // cout << "2*a = " << 2 * a << endl;
                visited[2 * a] = true;
                cnt[2 * a] = cnt[a] + 1;
                q.push(2 * a);
            }
    }
    return 0;
}