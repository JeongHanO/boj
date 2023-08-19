#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
int ans = 0;
bool alphabet[26];
vector<string> v;

int bigger(int a, int b) {if (a > b) return a; return b;}

int check(){
    bool read;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        read = true;
        string str = v[i];
        for(int j = 0; j < str.length(); j++){
            if(!alphabet[str[j]-'a']){
                read = false;
                break;
            }
        }
        if(read) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt){
    if(cnt == k){
        ans = bigger(ans, check());
        return;
    }

    for(int i = idx; i < 26; i++){
        if(alphabet[i] == true) continue;
        alphabet[i] = true;
        dfs(i, cnt+1);
        alphabet[i] = false;
    }
}

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        v.push_back(a);
    }

    if(k < 5){
        cout << 0;
        return 0;
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    
    k -= 5;

    dfs(0,0);

    cout << ans;
    return 0;
}


