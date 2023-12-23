#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std; 

vector <char> v;
vector <bool> check;
set <int> se;

bool prime_check(int x){
    if(x==0||x==1)return false; 
    for(int i=2; i<x; i++) if(x%i==0) return false;         
    return true; 
}

void dfs(int level, string s){   
    if(level>=1){
        if(prime_check(stoi(s))) se.insert(stoi(s)); 
    }
    for(int i=0; i<v.size(); i++){
        if(check[i]==true)continue; 
        check[i]=true; 
        dfs(level+1, s+v[i]); 
        check[i]=false; 
    }   
}

int solution(string numbers) {
    for(int i=0; i<numbers.size(); i++) v.push_back(numbers[i]);            
    check.resize(v.size(),false); 
    dfs(0, "");    
    return se.size();
}