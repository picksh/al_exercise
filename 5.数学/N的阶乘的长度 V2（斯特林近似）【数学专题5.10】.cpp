#include<cstdio>
/*
ll ans = log10(2*pi*n)/2 + n*(log10(n/exp(1.0)));
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define ll long long
#define MAXN 100007
#define MAXM 10007
#define pi 3.1415926

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll ans = log10(2*pi*n)/2 + n*(log10(n/exp(1.0)))+1;
		printf("%lld\n",ans);
		
	}
 } 
