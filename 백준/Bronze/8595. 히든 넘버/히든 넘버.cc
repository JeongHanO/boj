#include <bits/stdc++.h>
using namespace std;

char str[5000001]; 

int main()
{
	int n;
	long long sum=0, res=0; 

	scanf("%d", &n);
	scanf("%s", &str);
	
	for(int i=0;i<n;i++)
	{ 
		if(str[i] >= 48 && str[i] <= 57) 
		{
			sum=sum*10+str[i]-48; // 0*10 + 1, 1*10+3			
		}	
		else
		{
			res+=sum;
			sum=0;	
		}
	}	
	res+=sum; 
	printf("%lld\n", res);
}