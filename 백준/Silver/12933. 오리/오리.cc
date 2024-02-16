#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int ans = 0;
    cin >> s;

    vector<stack<char>> v;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'q'){
            stack<char> s;
            s.push('q');
            v.push_back(s);
            ans = max(ans, (int)v.size());
        }
        else if(s[i] == 'u'){
            bool check = false;
            for(auto &it: v){
                if(it.top() == 'q'){
                    it.push('u');
                    check = true;
                    break;
                }
            }
            if(!check){
                cout << -1;
                return 0;
            }
        }
        else if(s[i] == 'a'){
            bool check = false;
            for(auto &it: v){
                if(it.top() == 'u'){
                    it.push('a');
                    check = true;
                    break;
                }
            }
            if(!check){
                cout << -1;
                return 0;
            }
        }
        else if(s[i] == 'c'){
            bool check = false;
            for(auto &it: v){
                if(it.top() == 'a'){
                    it.push('c');
                    check = true;
                    break;
                }
            }
            if(!check){
                cout << -1;
                return 0;
            }
        }
        else if(s[i] == 'k'){
            bool check = false;
            for(int j = 0; j < v.size(); j++){
                stack<char> tmp = v[j];
                if(tmp.top() == 'c'){
                    v.erase(v.begin()+j);
                    check = true;
                    break;
                }
            }
            if(!check){
                cout << -1;
                return 0;
            }
        }
    }
    if(v.size() == 0) cout << ans;
    else cout << -1;
    return 0;
}