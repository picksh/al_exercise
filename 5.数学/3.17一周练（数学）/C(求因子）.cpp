/*结论：对于任意的整型N，
分解质因数得到N= P1^x1 * P2^x2* …… * Pn^xn;
则N的因子个数M为 M=（x1+1） * （x2+1） * …… *（xn+1）*/ 

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
#define MAXN 1000007
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

lu getans(lu x)
{
	lu ans=1;
	for(int i=0;i<cnt&&prime[i]*prime[i]<=x;i++){
		if(x%prime[i]==0){
			int count=0;
			while(x%prime[i]==0){
				count++;
				x/=prime[i];
			}
			ans*=(1+count);
			//if(x==1) return ans;
		}
	}
	return x>1?ans*(1+1):ans;
}

int main()
{
	int t,cas=0;
	lu n;
	getprime();
//	cout<<cnt;
	scanf("%d",&t);
	while(t--){
		cas++;
		scanf("%llu",&n);
	//	if(n!=1)
		printf("Case %d: %llu\n",cas,getans(n)-1);
	//	else printf("Case %d: 0\n");
	}
	return 0;
}
