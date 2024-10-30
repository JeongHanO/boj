#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> graph[3001];
vector<int> cycle;
vector<bool> visited;

vector<int> path;

void dfs(int start, int now, int dist) {
	for (int i = 0; i < graph[now].size(); i++) {
		if (dist > 1 && graph[now][i] == start) {
			for (int j = 0; j < n + 1; j++) {
				if (!visited[j])continue;
				cycle[j] = 0;
			}
			return;
		}
		if (visited[graph[now][i]]) continue;
		visited[graph[now][i]] = true;
		dfs(start, graph[now][i], dist + 1);
		visited[graph[now][i]] = false;
	}
}

void calcDist(int now, int before) {
	for (int i = 0; i < graph[now].size(); i++) {
		if (!cycle[graph[now][i]] || graph[now][i] == before) continue;
		if (cycle[graph[now][i]] != 0) {
			cycle[graph[now][i]] = cycle[now] + 1;
			calcDist(graph[now][i], now);
		}
	}
}

int main() {
	cin >> n;
	cycle.resize(n + 1, -1);
	
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!cycle[i]) continue;
		visited.clear();
		visited.resize(n+1, false);
		visited[i] = true;
		dfs(i, i, 0);
	}

	for (int i = 1; i <= n; i++) {
		if (!cycle[i]) calcDist(i, 0);
	}

	for (int i = 1; i <= n; i++) {
		cout << cycle[i] << ' ';
	}
}