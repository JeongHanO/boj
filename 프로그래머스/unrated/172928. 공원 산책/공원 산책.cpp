#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int h = park.size()-1;
    int w = park[0].size()-1;
    
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[i].size(); j++){
            if(park[i][j] == 'S'){
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
        if(answer.size() == 2) break;
    }
    
    for(int i =0; i < routes.size(); i++){
        int x = answer[0];
        int y = answer[1];
        
        char dist_char = routes[i][2];
        int dist = dist_char - '0';
        
        bool move = true;
        switch(routes[i][0]){
            case 'N':
                for(int j = 1; j <= dist; j++){
                    if(x-j < 0 || park[x-j][y] == 'X') {
                        move = false;
                        cout << "ASD:" << x-j << endl;
                        break;
                    }
                }
                if(move) answer[0] = x-dist;
                break;
            case 'S':
                for(int j = 1; j <= dist; j++){
                    if(x+j > h || park[x+j][y] == 'X') {
                        move = false;
                        break;
                    }
                }
                if(move) answer[0] = x+dist;
                break;
            case 'W':
                for(int j = 1; j <= dist; j++){
                    if(y-j < 0 || park[x][y-j] == 'X') {
                        move = false;
                        break;
                    }
                }
                if(move) answer[1] = y-dist;
                break;
            case 'E':
                for(int j = 1; j <= dist; j++){
                    if(y+j > w || park[x][y+j] == 'X') {
                        move = false;
                        break;
                    }
                }
                if(move) answer[1] = y+dist;
                break;
        }
    }
    return answer;
}