#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
vector<char> path;

char jaeum[] = { 'a', 'e', 'i', 'o', 'u' };

void check(vector<char> path) {
	int ja = 0, mo = 0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < 5; j++) {
			if (path[i] == jaeum[j]) {
				mo++;
				break;
			}
		}
	}
	ja = L - mo;
	if (ja >= 2 && mo >= 1) {
		for (char it : path) cout << it;
		cout << '\n';
	}
	return;
}

void dfs(int idx, int depth) {
	if (depth == L) {
		check(path);
		return;
	}
	for (int i = idx; i < C; i++) {
		path.push_back(v[i]);
		dfs(i + 1, depth+1);
		path.pop_back();
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
}