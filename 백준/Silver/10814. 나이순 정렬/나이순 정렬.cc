#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, string>> v;
	while (n--) {
		int a; string b; cin >> a >> b;
		v.push_back({ a,b });
	}

	stable_sort(v.begin(), v.end(), cmp);
	for (auto it : v) {
		cout << it.first << ' ' << it.second << '\n';
	}
}