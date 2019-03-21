#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 100007
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int n,c;
long long a[MAXNUM];

bool judge(int x)
{
	int temp=a[0];
	int sum=1;
	for(int i=0;i<n;i++){
		if(a[i]-temp>=x){
			sum++;
			temp=a[i];
		}
		if(sum>=c)return true;
	}
	return false;
 } 

int getans()
{
	int l=0;
	int r=a[n-1]-a[0];
	int mid;
	while(l<=r)
	{
		mid=(r+l)/2;                
		if(judge(mid)) 
		l=mid+1;      //#####注意这里的写法，防止找到中间的时候死循环。 
		else r=mid-1;
	}
	return l-1;
}

int main()
{
//	freopen("a.txt","r",stdin);
	while(scanf("%d%d",&n,&c)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		printf("%d\n",getans());
		memset(a,0,sizeof(a));
	} 
}
