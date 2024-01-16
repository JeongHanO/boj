#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> ans;
vector<vector<string>> ticket;
bool check[10001];
bool is_correct;

void dfs(string airport, int cnt_ticket){
    ans.push_back(airport);
    
    if(cnt_ticket == ticket.size()){
        is_correct = true;
    }
    for(int i = 0; i < ticket.size(); i++){
        if(check[i]) continue;
        if(ticket[i][0] == airport){
            check[i] = true;
            dfs(ticket[i][1], cnt_ticket+1);
            
            if(!is_correct){
                ans.pop_back();
                check[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    dfs("ICN", 0);
    
    return ans;
}