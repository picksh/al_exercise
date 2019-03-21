#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define EPS (10e-8)
#define MAXNUM 200007
using namespace std;

int tree[4*MAXNUM];
int num[MAXNUM];
void buildup(int index)
{
	tree[index]=max(tree[index*2],tree[index*2+1]); 
}

void build(int index,int l,int r)
{
	if(r==l){
		tree[index]=num[l];
		return;
	}
	int m=(l+r)/2;
	build(2*index,l,m);
	build(2*index+1,m+1,r);
	buildup(index);
}

//求区间[begin,end]的num[i]之和 [l,r]为总的区间 
int query(int index,int begin,int end,int l,int r)
{
	int ans=0;
  	if(begin>r||end<l)return -1;
  	if(begin<=l&&end>=r) return tree[index];
  	int m=(l+r)/2;
  	int p1=query(index*2,begin,end,l,m);
  	int p2=query(index*2+1,begin,end,m+1,r);
  	if(p1!=-1)ans=max(ans,p1);
  	if(p2!=-1)ans=max(ans,p2);
  	return ans;
}

void update(int index,int l,int r,int a,int num)
{
	if(l==r){tree[index]=num;return;}
	int m=(l+r)/2;
  	if(m>=a) update(index*2,l,m,a,num);
  	else update(index*2+1,m+1,r,a,num);
  	buildup(index);
}

int main()
{
//	freopen("2.txt","r",stdin);
	int l,r,begin,end,N,M,a,b;
	char com[2];
	while(scanf("%d%d%",&N,&M)!=EOF){
		memset(num,0,sizeof(num));
		memset(tree,0,sizeof(tree));
		int ans=0;
		for(int i=1;i<=N;i++){
			scanf("%d",&num[i]);
		}
	build(1,1,N);
//	for(int i=1;i<10;i++){
//		printf("我是%d ",tree[i]);
//	}
	while(M--){
		scanf("%s",com);
		scanf("%d%d",&a,&b);
		switch(com[0]){
			case'Q':{
				ans=query(1,a,b,1,N);
				printf("%d\n",ans);
				break;
			}
			case'U':{
				update(1,1,N,a,b);
				break;
			}
		}
}
}
    return 0;
}
