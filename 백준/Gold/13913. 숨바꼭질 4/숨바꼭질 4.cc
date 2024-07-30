#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
pair<int, int> arr[150001]; // 칸까지 걸린 초, 이전 인덱스

void bfs(int n) {
	queue<int> q;
	q.push(n);
	arr[n].first = 0;
	arr[n].second = -1;
	
	int cnt = 0;
	bool found = false;
	while (!q.empty() && !found) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (now == k) { // 도착지 찾음
				cout << arr[now].first << endl;
				found = true;
				break;
			}
			if (now + 1 <= 150000 && now+1 != n && arr[now+1].first == 0) {
				if(arr[now+1].first == 0)
				arr[now + 1] = { cnt, now };
				q.push(now + 1);
			}
			if (now - 1 >= 0 && now - 1 != n && arr[now - 1].first == 0) {
				if (arr[now - 1].first == 0)
				arr[now - 1] = { cnt, now };
				q.push(now - 1);
			} 
			if (now * 2 <= 150000 && now * 2 != n && arr[now * 2].first == 0) {
				if (arr[now * 2].first == 0)
				arr[now * 2] = { cnt, now };
				q.push(now * 2);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	if (k < n) {
		cout << n-k<< endl;
		for (int i = n; i >= k; i--) {
			cout << i << ' ';
		}
		return 0;
	}
	bfs(n);

	vector<int> v;
	int idx = k;
	v.push_back(k);
	while (idx != -1) {
		v.push_back(arr[idx].second);
		idx = arr[idx].second;
	}
	reverse(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}