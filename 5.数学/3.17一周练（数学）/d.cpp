#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#define MAXN 108
#define eps 0.00000001
#define lu unsigned long long
#define ll long long;
#define INF 0x7fffffff//1000000008

using namespace std;
int prime[MAXN];
bool mark[MAXN];
int cnt=0;

void getprime()
{
	for(int i=2;i<MAXN;i++){
		if(!mark[i])
		prime[cnt++]=i;
		for(int j=0;j<cnt&&prime[j]*i<MAXN;j++){
			mark[prime[j]*i]=true;
		}
	}
}

void getans(int x)
{
	for(int i=0;i<cnt&&prime[i]<=x;i++){
		int temp=x;
		int y=0;
		while(temp){
			y+=(temp/=prime[i]);
		}
		if(y){
			printf("%d (%d)",prime[i],y);
		}
		if(prime[i+1]<=x) printf(" * ");
	}
}

int main()
{
	int t,cas=0;
	int n;
	getprime();
//	cout<<cnt;
	scanf("%d",&t);
	while(t--){
		cas++;
		scanf("%d",&n);
		printf("Case %d: %d = ",cas,n);
		getans(n);
		printf("\n");
	}
	return 0;
}
