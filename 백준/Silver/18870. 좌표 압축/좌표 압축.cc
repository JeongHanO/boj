#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	vector<int> v(n);
	vector<int> tmp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	copy(v.begin(), v.end(), tmp.begin());
	sort(tmp.begin(), tmp.end());

	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin() << ' ';
	}
	
}