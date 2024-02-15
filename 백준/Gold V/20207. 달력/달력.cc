#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else{
        if(a.second > b.second) return true;
        else return false;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);

    int height = 1;
    int st = 0; 
    int end = 0; // 계획된 일정의 마지막. 직사각형의 끝부분.

    vector<pair<int, int>> tmp;
    for(auto i: v){
        if(st == 0){ // 가장 처음
            st = i.first;
            end = i.second;
            tmp.push_back(i);
            continue;
        }
        if(end >= i.first){ // 앞과 뒤의 일정이 겹침
            bool able_add = false;
            for(auto it = tmp.begin(); it != tmp.end(); it++){
                pair<int, int>& j = *it;
                if(j.second < i.first){ // 다른 일정의 뒤에 붙을 수 있음
                    end = max(end, i.second);
                    j.second = i.second;
                    able_add = true;
                    break;
                }
            }
            if(!able_add){ // 다른 일정 뒤에 못 붙음
                height++;
                end = max(end, i.second);
                tmp.push_back(i);
            }
        }
        else if(end+1 == i.first){ // 연속된 일정
            end = i.second;
            tmp.push_back(i);
        }
        else if(end+1 < i.first){ // 일정간 관계 X
            ans += (end-st+1)* height;
            tmp.clear();
            height = 1;
            st = i.first;
            end = i.second;
            tmp.push_back(i);
        }
    }
    ans += (end-st+1)*height;
    cout << ans;
}