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
#define ll long long
#define MAXN 6000007
#define MAXM 10007
#define pi 3.1415926

using namespace std;

int t,n;
ll phi[MAXN];
ll ans[MAXN];

void getouler()
{
	phi[1]=1;
	for(int i=2;i<=MAXN;i++){
		phi[i]=i;
	}
	for(int i=2;i<=MAXN;i++){
		if(phi[i]==i){
			for(int j=i;j<=MAXN;j+=i) phi[j]=phi[j]/i*(i-1);
		}
	}
}

void getans()
{
//	ll ans=0;
    memset(ans,0,sizeof(ans));
	for(ll i=1;i<=MAXN;i++){
		for(ll k=2;k<=MAXN;k++){
			if(i*k<=MAXN)
			ans[i*k]+=i*phi[k];
			else break;
		}
	}
	for(int i=2;i<=MAXN;i++) ans[i]+=ans[i-1];
}

int main()
{
	getouler();
	getans();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
}
