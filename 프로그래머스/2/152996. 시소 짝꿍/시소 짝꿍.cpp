#include <string>
#include <vector>
using namespace std;

long long solution(vector<int> w) {
    long long answer = 0;
    
    vector<long long> v(1001, 0);
    
    for(int i = 0; i < w.size(); i++){
        v[w[i]]++;
    }
    
    for(int i = 0; i < w.size(); i++) {
        if(w[i] % 2 == 0) {
            long long base  = (w[i]/2) * 3;
            if(base <= 1000)    answer += v[base];
        }
        if(w[i] % 3 == 0) {
            long long base  = (w[i]/3) * 4;
            if(base <= 1000) answer += v[base];
        }
        long long base  = w[i] * 2;
        if(base <= 1000) answer += v[base];
    }
    
    for(int i = 100; i <= 1000; i++) {
        if(v[i] >= 2)
            answer += (long long)(v[i] * (v[i]-1)) / 2; //n개 중에 2개 뽑는 경우의 수 : n(n-1) / 2
    }
    
    return answer;
}