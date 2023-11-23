#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    for(int i = 0; i < gems.size(); i++){
        if(m.find(gems[i]) == m.end()){
            m.insert({gems[i], 0});
        }
    }
    
    int cnt_gem = m.size();
    int size = 100001;
    int left = 0; int right = 1;
    
    m[gems[0]] = 1;
    cnt_gem--;
    if(cnt_gem == 0){
        return {1, 1};
    }
    for(int i = 1; i < gems.size(); i++){
        right = i;
        if(m[gems[i]] == 0){ // 구간에 없는 보석이면
            m[gems[i]]++;
            cnt_gem--;
        }
        else{ // 구간에 있는 보석이면
            m[gems[i]]++;
            if(gems[left] == gems[i]){ // 가장 앞과 같으면
                // 가장 앞의 원소가 구간 사이에 2개 이상 있는 원소이면 삭제.
                while(m[gems[left]]>1){
                    m[gems[left]]--;
                    left++;
                }
                
            }
            
        }
        if(cnt_gem == 0){ // 모든 보석을 포함했을 때
                // 최단 길이인지 확인후 갱신
                if(size > right - left){
                    size = right - left;
                    answer.clear();
                    answer.push_back(left+1);
                    answer.push_back(right+1);
                }
            }
    }
    
    return answer;
}

/*
모든 보석을 하나씩 포함해야함 -> set이나 map 사용?

보석의 가장 앞부터 하나씩 탐색하면서 종류별로 모이는지 확인.
시작 번호와 끝 번호 변수를 하나씩 두고 그 두 개를 증가시켜가면서 확인.


보석의 종류가 늘지 않았을 때, 새롭게 포함된 보석이 가장 앞의 보석과 같으면 가장 앞 하나 삭제.
가장 앞의 것을 하나 삭제한 뒤, 그 뒤에 오는 보석이 배열 안에 몇 개가 있는지 확인.
2개 이상이면 삭제.
삭제를 반복하다 배열에 1개만 있는 보석이면 삭제 중지.

BCACBD
- B부터 A까지 추가 -> C 추가 -> B추가 -> 가장 앞 B 삭제(새로운 것과 중복) -> 가장 앞 C 삭제(개수2개)
*/