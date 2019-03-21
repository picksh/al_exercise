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
int m[MAXN];


int CRT(int a[],int m[],int n)
{
	int M=1;
	for(int i=0;i<n;i++) M*=m[i];
	int ret=0;
	for(int i=0;i<n;i++){
		int x,y
		int tm=M/m[i];
		extend_gcd(tm,m[i],x,y);
		ret=(ret+tm*m[i]*x);
	}
	return ret;
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

