#include <bits/stdc++.h>
using namespace std;

string solution(string bin1, string bin2) {
    if(bin1==bin2&&bin1=="0") return "0";
    
    int sum = stoi(bin1)+stoi(bin2);
    vector<int> v;
    while(sum>0){
        v.push_back(sum%10);
        sum/=10;
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i]<2) continue;
        v[i+1]++;
        v[i]=v[i]-2;
    }
    if(v[v.size()-1]>1){
        v[v.size()-1]=v[v.size()-1]-2;
        v.push_back(1);
    }
    reverse(v.begin(),v.end());
    
    string ans="";
    for(int i=0;i<v.size();i++){
        ans+=v[i]+'0';
    }
    return ans;
}