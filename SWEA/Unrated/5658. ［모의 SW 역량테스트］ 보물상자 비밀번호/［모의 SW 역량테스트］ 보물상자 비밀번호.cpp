#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

int N, K; // 문자열 길이 , K번째로 큰 수 


long long hextodec(string s) {
	 // 16 -> 10진수
     // 1 2 3 4 5 6 7 8 9 A B C D E F 

	// AAA
	long long ret = 0;
	for (int i = 0; i < s.size(); i++)
	{

		ret *= 16;
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			 ret += s[i] - 'A' + 10;
		}	
		else
		{
			ret += s[i]-'0';
		}
	}



	return ret;


}
int main()
{
	int T;
	cin >> T;

	string s;
	deque<char>dq;
	set<string>sets;
	vector<string>v_parse;
	for (int tc = 1; tc <= T; tc++)
	{
		v_parse.clear();
		
		int N, K;
		cin >> N >> K;
		cin >> s;
		
		for (int i = 0; i < s.size(); i++)
		{
			dq.push_back(s[i]);
		} // 내가 생각한 코드 

		s += s; // 편하게 후보 길이를 두배로
		vector<string>v;


		//1 후보들 만들기
		//str.substr(시작,크기);

		for (int i = 0; i < N; i++)
		{
			v.push_back(s.substr(i, N / 4));
			sets.insert(s.substr(i, N / 4));
		}



		//2 크기 순서 정렬
		sort(v.rbegin(), v.rend());
	

		for (int i = 0; i < v.size(); i++)
		{
			if (i == 0 ||v[i] != v[i - 1])
			{
				v_parse.push_back(v[i]);
			}
		}

		long long ans = 0;
		ans = hextodec(v_parse[K-1]); //FFFFFFF << long long

		// out

		cout << "#" << tc << " " << ans << endl;
		int de = -1;

		//3 중복 제외
	
	
	
	
	
	
	
		
	
	
	
	
	}
}