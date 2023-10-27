#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_prefix) {
    size_t found = my_string.rfind(is_prefix);
    if(found != string::npos && found == my_string.size() - is_prefix.size()){
        return 1;
    }
    return 0;
}