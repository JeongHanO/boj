#include <string>
#include <vector>

using namespace std;

int solution(int n, string c) {
    for(int i = 0; i < c.size(); i++){
        switch(c[i]){
            case 'w':
                n += 1;
                break;
            case 's':
                n -= 1;
                break;
            case 'd':
                n += 10;
                break;
            case 'a':
                n -= 10;
                break;
        }
    }
    return n;
}