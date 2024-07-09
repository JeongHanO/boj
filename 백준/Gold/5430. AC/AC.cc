// https://www.acmicpc.net/problem/5430
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string str; cin >> str;
		int n; cin >> n;
		deque<int> q;
		
		string num; 
		char a;
		while(true) {
			char a; cin >> a;
			if (a == ']') break;
			if (isdigit(a)) num += a;
			else if (!num.empty()) {
				q.push_back(stoi(num));
				num.clear();
			}
		}
		if (!num.empty()) {
			q.push_back(stoi(num));
			num.clear();
		}

		bool f = true;
		string s = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') {
				f = !f;
			}
			else if(str[i] == 'D'){
				if (q.size() == 0) {
					s = "error";
					break;
				}
				else if (f) q.pop_front();
				else q.pop_back();
			}
		}
		if (s == "error") cout << s << endl;
		else {
			if (!f && q.size() > 0) reverse(q.begin(), q.end());
			if (q.size() == 0) {
				cout << "[]" << endl;
				continue;
			}
			cout << '[' << q.front();
			q.pop_front();
			int size = q.size();
			for (int i = 0; i < size; i++) {
				cout << ',' << q.front();
				q.pop_front();
			}
			cout << ']' << endl;
		}

	}
}
