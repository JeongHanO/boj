#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int sum = 0;
    
    
    while(s != "1"){
        string tmp = "";
        cnt++;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                sum++;
            } else{
                tmp += "1";
            }
        }
        
        int num = tmp.size();
        s = "";
        while(num > 0){
            s += to_string(num%2);
            num /= 2;
        }
        cout << s << endl;   
    }
    
    answer.push_back(cnt);
    answer.push_back(sum);
    return answer;
}