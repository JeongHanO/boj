#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s, string p) {
    int answer = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') s[i] = 'B';
        else s[i] = 'A';
    }
    
    for(int i = 0; i < s.size()-p.size()+1; i++){
        bool a = true;
        for(int j = 0; j < p.size(); j++){
            if(s[i+j] != p[j]){
                a = false;
                break;
            }
        }
        if(a) return 1;
    }
    return 0;
}