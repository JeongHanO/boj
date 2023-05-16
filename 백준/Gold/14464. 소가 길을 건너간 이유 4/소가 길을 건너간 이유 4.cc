#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Cow{
    int s,e;
};
 
struct cmp{
    bool operator()(Cow a, Cow b){
        if(a.e != b.e) return a.e > b.e;
        return a.s > b.s;
    }
};
 
int c, n;
int t;
int ans=0;
 
vector<pair<int, int> > chicken; // 시간, 수행했는지 여부  
priority_queue<Cow, vector<Cow>, cmp> cow; // 끝나는 시간 기준으로 오름차순 저장. 최소 힙. 
 
 
bool c_cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> n;
 
    for(int i=0; i<c; i++){
        cin >> t;
        chicken.push_back({t, 0});
    }
    
    int s, e;
    for(int i=0; i<n; i++){
        cin >> s >> e;
        cow.push({s, e});
    }
    
    sort(chicken.begin(), chicken.end(), c_cmp);
    
    // 소를 하나씩 꺼내서 닭의 시간과 맞는지 확인하기  
    while(!cow.empty()){
        for(int i=0; i<c; i++){
            if(chicken[i].first >= cow.top().s && chicken[i].first <= cow.top().e && chicken[i].second == 0){
                ans ++;
                chicken[i].second = 1;
                break;
            }
        }
        cow.pop();
    }
 
    cout << ans << endl;
}
