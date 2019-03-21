#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
#define MAXN 100007

using namespace std;

ull n;

int main()
{
	scanf("%llu",&n);
	if(n<3) printf("%llu\n",n);
	else{
		if(n==3) printf("6\n");
	    else{
		if(n&1) printf("%llu\n",(ull)(n-1)*(n-2)*n);
		else{
			if(n%3!=0) printf("%llu\n",(ull)n*(n-1)*(n-3));
			else printf("%llu\n",(ull)(n-1)*(n-2)*(n-3));
		}
	}
		
	}
	
	return 0;
}
