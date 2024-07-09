#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	while (true) {
		vector<int> v;
		cin >> a >> b >> c;
		if (a == 0) break;
		bool tri = false;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());

		if (v[2] * v[2] == v[1] * v[1] + v[0] * v[0]) tri = true;

		if (tri) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}