#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define MAXN 100007
#define MAXM 10007
#define pi 3.1415926

int getouler(int x)
{
	int ans=x;
	int temp=x;
	for(int i=2;i<=sqrt(x)+1;i++){
		if(temp==1) break;
		if(temp%i==0){
			ans=ans/i*(i-1);
		}
		while(temp%i==0) temp/=i;
	}
	if(temp!=1) ans=ans/temp*(temp-1);
	return ans;
 } 


int main()
{
	//getouler();
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",getouler(n));
	}
	return 0;
 } 
