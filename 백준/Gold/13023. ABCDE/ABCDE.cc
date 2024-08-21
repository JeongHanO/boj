#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int a, b;
vector<int> v[2001];
int dat[2001];
int flag;

void solution(int seq, int now) {
	if (seq == 5)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < v[now].size(); i++)
	{
		if (dat[v[now][i]]) continue;
		dat[v[now][i]] = 1;
		solution(seq + 1, v[now][i]);
		dat[v[now][i]] = 0;
	}
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		int t, r;
		cin >> t >> r;
		v[t].push_back(r);
		v[r].push_back(t);
	}
	for (int i = 0; i < a; i++)
	{
        dat[i] = 1;
        solution(1, i);
        dat[i] = 0;
        if(flag) break;
	}
	cout << flag;
}