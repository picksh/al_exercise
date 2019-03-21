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
int x1,x2,y2,y,a,b;
int x0,yo;

void getk()
{
	a=x1-x2;
	if(a<0){
		a=-a;
		x2=x1-a;
	}
	x0=x2;
	b=y-y2;
	if(b<0){
		b=-b;
		y2=y-b;
	}
	yo=y2;
//	cout<<"a="<<a<<" b="<<b<<"\n";
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}


int main()
{
	int t,cas=0;
	int n;
	scanf("%d",&t);
	int tot=0;
	while(t--){
		int ans=0;
		tot++;
		scanf("%d%d%d%d",&x1,&y,&x2,&y2);
		getk();
//		cout<<"a="<<a<<" b="<<b<<"\n";
		int aa=a/gcd(a,b);
//		cout<<gcd(a,b)<<"\n";
		int bb=b/gcd(a,b);
//		cout<<"a="<<a<<" b="<<b<<"\n";
		if(a==0||b==0){
			ans=(a==0)?abs(y-y2+1):abs(x1-x2+1);
			printf("Case %d: %d\n",tot,ans);
			
		}else{
			for(int i=0;x0+i*aa<=x1&&yo+i*bb<=y;i++){
			ans++;
		}
		printf("Case %d: %d\n",tot,ans);
		}
	}
	return 0;
}
