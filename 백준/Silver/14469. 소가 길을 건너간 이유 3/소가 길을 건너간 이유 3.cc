#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int, int> > pq;
    int arrvaltime, duration;

    for(int i = 0; i < n; i++){
        cin >> arrvaltime >> duration;
        pq.push(make_pair(-arrvaltime, duration));
    }
    
    int dur = pq.top().second;
    int time = -pq.top().first + dur;
    pq.pop();
    
    while(!pq.empty()){
        int nxt_enter = -pq.top().first;

        
        if(nxt_enter < time){
            time += pq.top().second;
        }
        else{
            time = nxt_enter + pq.top().second;
        }
        pq.pop();
    }

    cout << time <<  endl;
}