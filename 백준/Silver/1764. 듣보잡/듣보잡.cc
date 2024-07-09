#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main() {
	int n, m, cnt = 0;
	string s;
	vector<string> result;
	map<string, bool> list;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		list.insert(make_pair(s, true));
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (list[s]) {
			result.push_back(s); 
			cnt++; 
		}
	}
	cout << cnt << '\n';
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
