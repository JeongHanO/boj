#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a = n, b = n;
    int a_cnt = 0, b_cnt = 0;

    int up_cnt = 0;
    int down_cnt = 0;
    int last_price = -1;

    for(int i = 0; i < 14; i++){
        int price; cin >> price;
        if(price <= a){ // 준현이 매수
            int tmp_cnt = a / price;
            a_cnt += tmp_cnt;
            a -= price * tmp_cnt;
        }
        if(price > last_price){ //주가 상승
            up_cnt++;
            down_cnt = 0;
        }
        else if(price < last_price){ //주가 하락
            down_cnt++;
            up_cnt = 0;
        }
        else{ //주가 동결
            up_cnt = 0;
            down_cnt = 0;
        }
        last_price = price;
        
        if(up_cnt == 3){ // 3일 연속 상승
            b += b_cnt * price;
            b_cnt = 0;
        } 
        else if(down_cnt >= 3){ // 3일 연속 하락
            int tmp_cnt = b / price;
            b -= price * tmp_cnt;
            b_cnt += tmp_cnt;
        }
    }

    a += last_price * a_cnt;
    b += last_price * b_cnt;

    if(a > b) cout << "BNP";
    else if (a < b) cout << "TIMING";
    else cout << "SAMESAME";

    return 0;
}