/*HDU - 1506*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<stack>
#define INF 100000000
#define MAXNUM 100007 
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int num[MAXNUM];

struct hei{
	int index;
	long long height;
}h[MAXNUM];

int main()
{
//freopen("c.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(num,0,sizeof(num));
		long long ans=0;
		h[0].height=-1;
		int s=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			h[i].height=0;
			h[i].index=0;
		}
		for(int i=1;i<=n;i++){
			while(num[i]<h[s].height){ 
				ans=max(ans,(i-h[s-1].index-1)*h[s].height);
				s--;
				
			}
			s++; 
			h[s].height=num[i];
			h[s].index=i;
		}		
		for(int i=s;i>0;i--){
			ans=max(ans,(n-h[i-1].index)*h[i].height);//这里 长度 为 n-h[i-1].index特别注意！！ h[i-1].index的num若比h[i].height小，那就在栈里；若不在栈里，则一定比它大。 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
