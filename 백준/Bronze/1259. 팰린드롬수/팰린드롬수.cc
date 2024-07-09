#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	while (1) {
		cin >> a;
		if (a == "0") break;
		bool y = true;
		for (int i = 0; i < a.size() / 2; i++) {
			if (a[i] != a[a.size() - i - 1]) {
				y = false; 
				break;
			}
		}
		if (y) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}