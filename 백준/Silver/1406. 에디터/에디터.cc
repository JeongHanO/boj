#include <iostream>
#include <string>
#include <list>
 
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
    list<char> l(s.begin(), s.end());
    auto idx = l.end();
    while(n--)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'L':
            if (idx != l.begin())
                idx--;
            break;
        case 'D':
            if (idx != l.end())
                idx++;
            break;
        case 'B':
            if (idx != l.begin())
                idx = l.erase(--idx);
            break;
        case 'P':
            char c1;
            cin >> c1;
            l.insert(idx, c1);
            break;
        }
    }
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it;
    }
}