#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MAX_SIZE = 500;
 
bool cmp(const vector<int>& a, const vector<int>& b){
    return a.size() < b.size();
}
 
vector<int> solution(string s) {
    vector<vector<int>> s_in(MAX_SIZE, vector<int>());
 
    int n = 0;
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tmp += s[i];
        }
        else{
            if(s[i] == ',' && !tmp.empty()){
                s_in[n].push_back(stoi(tmp));
                tmp = "";
            }
            if(s[i] == '}' && !tmp.empty()){
                s_in[n].push_back(stoi(tmp));
                n++;
                tmp = "";
            }
            
        }
    }
 
    sort(s_in.begin(), s_in.begin()+n, cmp);
 
    vector<int> answer;
    vector<bool> visited(100000+1, false);
    for(int c=0; c<n; c++){
        for(int r=0; r<s_in[c].size(); r++){
            if(!visited[s_in[c][r]]){
                answer.push_back(s_in[c][r]);
                visited[s_in[c][r]] = true;
            }
        }
    }
 
    return answer;
}