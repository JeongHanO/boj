#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

map<string, string> m;

vector<string> solution(vector<string> rec) {
    vector<string> answer;
    
    for(int i = 0; i < rec.size(); i++){
        stringstream stream;
        stream.str(rec[i]);
        string s1, s2, s3;
        stream >> s1 >> s2 >> s3;
        
        if(s1 == "Enter"){
            if(m.find(s2) != m.end()){
                m[s2] = s3;
            }else{
                m.insert({s2, s3});    
            }
        }
        else if(s1 == "Change"){
            m[s2] = s3;
        }
                
    }
    
    for(int i = 0; i < rec.size(); i++){
        stringstream stream;
        stream.str(rec[i]);
        string s1, s2, s3;
        stream >> s1 >> s2 >> s3;
        
        string s = "";
        
        if(s1 == "Enter"){
            s += m[s2];
            s += "님이 들어왔습니다.";
        }
        else if(s1 == "Leave"){
            s += m[s2];
            s += "님이 나갔습니다.";
        }
        else{
            continue;
        }
        
        answer.push_back(s);
    }
    
    return answer;
}

/*
1. uid 별로 최종적으로 결정된 ID map에 기록
2. record 순회하면서 uid별 올바은 ID를 map에서 찾아서 문장 생성
*/