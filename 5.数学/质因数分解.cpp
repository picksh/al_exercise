 #include<cstdio>
#include<iostream>
#include<cstdlib>
/*解方程组 x三ai(mod mi)*/ 

#include<algorithm>
#include<cstring>


#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<ctime>
#define MAXN 1000007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;
int a[MAXN];
int b[MAXN];


void getfactor(int x,int a[],int b[])
{
	memset(b,0,sizeof(b));
	int tot=0;
	int temp=x;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			while(x%i==0){
				a[tot]=x;
			    a[tot]++;
			    x/=i;
			}
		}
		tot++;
	}
	//如果不是1,说明最后剩下的也是质数 
	if(temp!=1){
		a[tot]=x;
		b[tot]++;
	}
}

int main()
{
    int n;
	while(scanf("%d",&n)!=EOF){
		int x;
		int ans;
		
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[x]++;
			if(a[x]>=(n+1)/2) ans=x;
		}

		printf("%d\n",ans);
		memset(a,0,sizeof(a));
	} 
    return 0;
}

