/*HDU - 1506   */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 100007
#define pi 3.1415926

using namespace std;
int h[MAXNUM];
int r[MAXNUM];
int l[MAXNUM];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&h[i]);
	    }
	    int t;
		l[0]=0;
		for(int i=1;i<n;i++){
			t=i;
			while(t>0&&h[i]<=h[t-1]) t=l[t-1];//这个是重点 
			l[i]=t;//记录最左大于等于它的 
		}
		r[n-1]=n-1;
		for(int i=n-2;i>=0;i--){
			t=i;
			while(t<n&&h[i]<=h[t+1]) t=r[t+1];//这个是重点 
			r[i]=t;//记录最左大于等于它的 
		}
		long long ans=0;
		long long s=0;
		for(int i=0;i<n;i++){
			s=h[i]*(r[i]-l[i]+1);
			ans=max(ans,s);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
