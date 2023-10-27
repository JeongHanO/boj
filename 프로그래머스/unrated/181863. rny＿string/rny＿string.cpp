#include <string>
#include <vector>

using namespace std;

string solution(string r) {
    string a = "";
    for(int i= 0;i<r.size();i++){
        if(r[i] == 'm') a += "rn";
        else a += r[i];
    }
    return a;
}