#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 크기 별로 개수를 카운트 하고, 카운트를 기준으로 정렬, 정렬된 숫자 중 큰 숫자부터 채택하면서 카운트.
    map<int, int> m;
    for(int i = 0; i < tangerine.size(); i++){ //크기별 개수 카운트
        if(m.find(tangerine[i]) != m.end()){
            m[tangerine[i]]++;
        } else {
            m.insert(make_pair(tangerine[i],1));
        }
    }
    
    vector<pair<int, int>> v;
    for(auto& i: m){
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += v[i].second;
        answer++;
        if(cnt >= k) break;
    }

    return answer;
}