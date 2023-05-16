#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 999999999
using namespace std;

int v, e, k;

vector<int> dijkstra(int v, int k, vector<pair<int, int> > graph[]){
    vector<int> dist(v+1, INF);
    dist[k] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, k));

    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < graph[cur_node].size(); i++){
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = graph[cur_node][i].second;

            if(dist[nxt_node] > cur_dist + nxt_dist){
                dist[nxt_node] = cur_dist + nxt_dist;
                pq.push(make_pair(-dist[nxt_node], nxt_node));
            }
        }
    }
    return dist;
}

int main(){
    cin >> v >> e >> k;
    vector<pair<int, int> > graph[v+1];
    for(int i = 0; i < e; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
    }
    
    vector<int> dist = dijkstra(v, k, graph);
    
    for(int i = 1; i <= v; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
