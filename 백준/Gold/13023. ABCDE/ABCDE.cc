#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool ans;
vector<int> v[2001];
bool visited[2001];

void dfs(int a, int depth) {
	if (depth == 5) {
		ans = true;
		return;
	}
	for (int i = 0; i < v[a].size(); i++) {
		if (!visited[v[a][i]]) {
			visited[v[a][i]] = true;
			dfs(v[a][i], depth + 1);
			visited[v[a][i]] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
		if (ans) break;
	}
	cout << ans;
}