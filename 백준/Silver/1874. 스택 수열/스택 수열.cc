#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 주어진 숫자까지 push, 주어진 숫자는 바로 pop
// 주어진 숫자가 stack의 길이보다 크면 위의 조건 실행
// 주어진 숫자가 stack의 길이보다 작으면 pop

int main(){
    int n;
    cin >> n;

    vector<int> v;
    stack<int> s;
    
    for(int i = 0;i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    int top;
    int tmp = 2;
    int max_num = 0;
    
    vector<char> opr;
    bool visited[100001] = {};

    s.push(1);
    opr.push_back('+');
    visited[1] = true;

    for(int i = 0; i < v.size(); i++){

        if(s.empty()){ top = 0; }
        else { top = s.top(); }

        if(top < v[i]){
            while(top < v[i]){
                s.push(tmp);
                max_num = tmp;
                top = s.top();  
                tmp++;
                opr.push_back('+');
            }
            s.pop();
            opr.push_back('-');
        }
        else if(top == v[i]){
            s.pop();
            opr.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    
    
    for(int i = 0; i < opr.size(); i++){
        cout << opr[i] << '\n';
    }
    return 0;
}