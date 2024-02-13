#include <string>
#include <vector>
using namespace std;

long long facto(int a){
    long long ans = 1;
    
    for(int i = 1; i <= a; i++){
        ans *= i;
    }
    
    return ans;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    
    int cnt=1;
    
    for(int i = 1; i <= n; i++){
        num.push_back(i);
    }
    
    while(cnt != n){
        long long tmp = facto(n-cnt);
        int idx = (k-1) / tmp;
        
        answer.push_back(num[idx]);
        num.erase(num.begin()+idx);
        
        cnt++;
        k %= tmp;
        
		if (k == 0)
			k = tmp;
    }
    
    answer.push_back(num[0]);
    return answer;
    
}