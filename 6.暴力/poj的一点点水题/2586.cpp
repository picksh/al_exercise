/*3069*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#define ll long long
#define mode 1000000007
#define MAXN  1007
#define INF 100000000
#define EPS 0.000000001

using namespace std;
int a[MAXN];
int b[MAXN];

int main()
{
	int r,n;
	while(scanf("%d%d",&r,&n)!=EOF&&r!=-1){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=-1;
		sort(a,a+n+1);
//		int begin=a[1];
		int temp=a[1];
		int ans=0;
		int begin=1;
		while(begin<=n){
			int i=begin+1;
			while(a[i]-a[begin]<=r&&i<=n) i++;
			temp=a[i-1];
			while(a[i]-temp<=r&&i<=n) i++;
//			if(i==n){
//				if(a[i]-temp<=r) break;
//			}
			ans++;
			begin=i;
			temp=a[i];
			
		}
//		for(int i=2;i<=n;i++){
//			while(a[i]-)
//			if(a[i]-begin<=r) temp=a[i];
//			else{
//				int flag=0;
//				while(a[i]-temp<=r&&i<n){
//					i++;
//					flag=1;
//				}
//				if(i==n&&flag==1){
//					if(a[n]-temp<=r) break;
//				}
//				ans++;
//			    temp=a[i];
//			    begin=a[i];
//			}
//		}
		printf("%d\n",ans);
	}
	return 0;
}
