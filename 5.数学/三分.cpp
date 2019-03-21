#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 1e15
#define MAXNUM 10010
#define eps 1e-11
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int T,n;
double a[MAXNUM];
double b[MAXNUM];
double c[MAXNUM];

double f(double x)
{
	double temp;
	double ans=-INF;
	for(int i=0;i<n;i++){
		temp=a[i]*x*x+b[i]*x+1.0*c[i];
		ans=max(ans,temp);
	}
	return ans;
}

double getans()
{
	double left=0;
	double right=1000;
	double mid;
	double mmid;
	while(right-left>eps){
		mid=(left+right)/2;
    	mmid=(mid+right)/2;
    //	if(f(mid)==f(mmid)) return (mid+mmid)/2; ######这里加上去就错了！！ 三分请不要管这个 
		if(f(mid)>f(mmid))left=mid;
		else right=mmid;
	}
	return f(left);
}

int main()
{
//	freopen("c.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
	}
		printf("%.4lf\n",getans());
//	memset(a,0,sizeof(a));
//	memset(b,0,sizeof(b));
//	memset(c,0,sizeof(c));
	}
	return 0;
}
