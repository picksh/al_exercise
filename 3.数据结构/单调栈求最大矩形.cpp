/*HDU - 4405   */

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
int l[MAXNUM];
long long sta[MAXNUM];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&h[i]);
		}
		long long ans=0;
		sta[0]=0;
		for(int i=1;i<=n;i++){
			l[i]=i;
		}
		int cent=0;
		for(int i=0;i<n;i++){
			if(h[i]>=sta[cent]){//注意这里是大于等于 因为等于的时候也是可以取到这个高度的 
				cent++;
				sta[cent]=h[i];
			}else{
				//找到左边比它大的全部 
				
				int k=cent-1;
				while(sta[k]>=h[i]){
					ans=max(ans,(cent-l[k]+1)*sta[k]);
					k--;
				}
				l[cent]=k+1;
				sta[k+1]=h[i];
				cent=k+1;
	
//				int k=lower_bound(sta,sta+cent,h[i])-sta;
//				l[i]=k;//最后还是要一 
//				sta[k]=h[i];
//				ans=max(ans,(cent-k+1)*)
//				cent=k;
			}
		}
//		cout<<sta[4]<<" "<<sta[3]; 
		int k=cent;
		while(cent){
			ans=max((sta[cent]*(k-l[cent]+1)),ans);
			cent--;
		}
		printf("%lld\n",ans);
		memset(sta,0,sizeof(sta));
	}
	return 0;
}
