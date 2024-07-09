#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	cout << stoi(a) + stoi(b) - stoi(c) << endl;
	string s = a + b;
	cout << stoi(s) - stoi(c);

}