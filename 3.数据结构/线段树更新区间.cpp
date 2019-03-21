/*
poj-2887
1.add c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
2.query the sum of Aa, Aa+1, ... , Ab.
*/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define EPS (10e-8)
#define MAXNUM 100007
using namespace std;

long long tree[4*MAXNUM];
long long num[MAXNUM];
long long mark[4*MAXNUM];
long long ans=0;

void buildup(int index)
{
	tree[index]=tree[index*2]+tree[index*2+1];
}

void pushdown(int index,long long l,long long r)
{
	long long len1,len2;
	if(mark[index]!=0){
		if((r-l+1)%2){
		len1=(r-l)/2+1;
		len2=(r-l)/2;
	    }else{
		len1=(r-l+1)/2;
		len2=len1;
	}
		mark[index*2]+=mark[index];
		mark[index*2+1]+=mark[index];
		tree[index*2]+=mark[index]*len1;
		tree[index*2+1]+=mark[index]*len2;
		mark[index]=0;
	}
	
}
void build(int index,long long l,long long r)
{
	if(r==l){
		tree[index]=num[l];
		return;
	}
	long long m=(l+r)/2;
	build(2*index,l,m);
	build(2*index+1,m+1,r);
	buildup(index);
}

//求区间[begin,end]的num[i]之和 [l,r]为总的区间 
void query(int index,long long begin,long long end,long long l,long long r,long long &ans)
{
  	if(begin>r||end<l)return;
  	if(begin<=l&&end>=r) {ans+=tree[index];return;}
  	pushdown(index,l,r);
  	long long m=(l+r)/2;
  	query(index*2,begin,end,l,m,ans);
  	query(index*2+1,begin,end,m+1,r,ans);
  	buildup(index);	
}
void change(int index,long long l,long long r,long long begin,long long end,long long num)
{
	if(begin>r||end<l)return;
  	if(begin<=l&&end>=r){
  		tree[index]+=(r-l+1)*num;
  		mark[index]+=num;
  		return;
	}
	pushdown(index,l,r);
	long long m=(l+r)/2;
    change(index*2,l,m,begin,end,num);
  	change(index*2+1,m+1,r,begin,end,num);
  	buildup(index);	
}
int main()
{
//	freopen("3.txt","r",stdin);
	long long l,r,begin,end,N,M,a,b,c;
	char com[2];
	while(scanf("%lld%lld",&N,&M)!=EOF){
		memset(num,0,sizeof(num));
		memset(tree,0,sizeof(tree));
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=N;i++){
			scanf("%lld",&num[i]);
		}
	build(1,1,N);
//	for(int i=1;i<20;i++){
//		printf("我是%d ",tree[i]);
//	}
//    for(int i=1;i<18;i++){
//			cout<<tree[i]<<" ";
//		}
	while(M--){
		long long ans=0;
		scanf("%s",com);
		switch(com[0]){
			case'Q':{
				scanf("%lld%lld",&a,&b);
				query(1,a,b,1,N,ans);
				printf("%lld\n",ans);
				break;
			}
			case'C':{
				scanf("%lld%lld%lld",&a,&b,&c);
				change(1,1,N,a,b,c);
				break;
			}
		}
    }
}
    return 0;
}
