#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	while (n--) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	for (auto it : v) {
		cout << it.first << ' ' << it.second << '\n';
	}
}