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
//double lo[MAXN];
double a[MAXN];

//void getlo()
//{
//	lo[1]=0;
//	for(int i=2;i<MAXN;i++){
//		lo[i]=(i%10==0)?lo[i-1]+1:lo[i-1];
//	}
//	for(int i=0;i<50;i++) cout<<lo[i]<<" ";
//	cout<<"\n";
//}

void initial()
{
//	a[1]=1;
    a[0]=0;
	for(int i=1;i<MAXN;i++){
		a[i]=a[i-1]+log10(i);
	}
//	for(int i=0;i<50;i++) cout<<a[i]<<" ";
//	cout<<"\n";
}

int getans(int x,int ba)
{
	if(x==0) return 1;
	return ceil(a[x]/log10(ba*1.0));
}

int main()
{
	int t,cas=0;
	int n,b;
//	getlo();
	initial(); 
//	cout<<cnt;
	scanf("%d",&t);
	while(t--){
		cas++;
		scanf("%d%d",&n,&b);
		printf("Case %d: %d\n",cas,getans(n,b));
	}
	return 0;
}
