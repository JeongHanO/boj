#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
 
int main(void)
{    
    int N;
    int ans = 0;
        
    cin >> N;
    
    int left = 1;
    int right = 1;
    int sum = 0;
    
    while(left <= right && right <= N+1)
    {        
        if(sum > N)
        {
            sum -= left;
            left++;
        }
        else if(sum < N)
        {
            sum += right;
            right++;
        }
        else if(sum == N)
        {
            ans++;
            
            sum += right;
            right++;
        }
    }
    
    cout << ans;
 
    return 0;
}
