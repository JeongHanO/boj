#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
 
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;
    
    map<string, int> m;
    
    for(int i = 0; i < genres.size(); i++){
        if(m.find(genres[i]) == m.end()){
            m.insert({genres[i], plays[i]});
        }
        else{
            m[genres[i]] += plays[i];
        }
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        int fir = 0, fir_idx = 0;
        int sec = 0, sec_idx = 0;
        for(int j = 0; j < genres.size(); j++){
            if (genres[j] == v[i].first){
                if (plays[j] > fir){
                    sec = fir;
                    sec_idx = fir_idx;
                    fir = plays[j];
                    fir_idx = j;
                    
                }
                else if (plays[j] > sec){
                    sec = plays[j];
                    sec_idx = j;
                }
            }
        }
        ans.push_back(fir_idx);
        if(sec > 0) ans.push_back(sec_idx);
    }
    
    return ans;
}

/*
장르 별 합계를 카운트.
map<string, int> genre_sum; string에 장르명, int에 누적 재생 횟수.
int를 비교하며 가장 많이 재생된 장르부터 노래 추출.



map<int, int, greater>; 첫 번째 int에 재생 횟수, 두 번째 int에 고유 번호.

*/