/*如果给出一个星星的坐标为(x,y)，
那么它的等级就等于前面已经输入的x坐标在[0,x]区间的星星数量。
*/
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
#include<ctime>
#define MAXN 65007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;
int tree[MAXN];
int ans[MAXN];
int n;
//int x[MAXN];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	while(x<MAXN){
		tree[x]++;
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int sum=0;
	while(x>0){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{  
    while(scanf("%d",&n)!=EOF){
    	memset(ans,0,sizeof(ans));
    memset(tree,0,sizeof(tree));
	//scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		ans[getsum(x+1)]++;
		update(x+1);
	} 
	for(int i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}	
	}
	return 0;
    
	
}
