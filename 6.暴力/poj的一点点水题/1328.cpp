/*1328*/

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
int n,d;

struct island{
	double l,r;
}p[MAXN];
int cnt;

bool dis(int x,int y)
{
	if(y>d||y<0||d<0){
	//	printf("-1\n");
		return false;
	}else{
    	double s=sqrt(d*d-y*y);
     	p[cnt].r=x+s;
     	p[cnt++].l=x-s;
	}
	return true;

}

bool cmp(island x,island b)
{
     return x.l<b.l;
}

int main()
{
	int tot=0;
	while(scanf("%d%d",&n,&d)!=EOF&&n!=0){
		tot++;
		memset(p,0,sizeof(p));
		int flag=1;
		cnt=0;
		int ans=1;
		int x,y;
		for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y); 
		if(!dis(x,y)) flag=0;
	    }
	    if(flag){
	    	sort(p,p+cnt,cmp);
	    //	for(int i=0;i<n;i++) cout<<p[i].l<<" "<<p[i].r<<"\n";
	    	double right=p[0].r;
	    for(int i=1;i<cnt;i++){
	    	if(right<p[i].l){
	    		ans++;
	    		right=p[i].r;
			}else{
				right=min(right,p[i].r);
			}
		}
		printf("Case %d: %d\n",tot,ans);
		}else printf("Case %d: -1\n",tot);
		getchar();
	}
	return 0;
 } 
