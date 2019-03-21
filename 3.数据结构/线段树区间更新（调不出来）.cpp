/*POJ - 3468 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 10000000
#define MAXNUM 200007
#define pi 3.1415926

using namespace std;
long long tree[MAXNUM*4];
long long num[MAXNUM];
long long mark[MAXNUM*4];
char qq[2];

void buildtree(int node,int begin,int end)
{
	if(begin==end){
		tree[node]=num[begin];
		return;
	}else{
		buildtree(node*2,begin,(begin+end)/2);
		buildtree(node*2+1,(begin+end)/2+1,end);
	}
	tree[node]=tree[node*2]+tree[node*2+1];

}

void pushdown(int node)
{
	if(mark[node]){
		mark[node*2]+=mark[node];
	    mark[node*2+1]+=mark[node];
	    mark[node]=0;//j记号向下传递后记得擦掉！！ 
	}
	return;
}

void update_p(int node)
{
	tree[node]=tree[node*2]+tree[node*2+1];
}

void update_ar(int node,int left,int right,int begin,int end,int value)//left,right为当前区间，begin,end为待更新区间。 
{
	if(left>end||right<begin) return; 
	if(left>=begin&&right<=end){
		tree[node]+=value*(right-left+1);
		tree[node]+=mark[node]*(right-left+1);
		mark[node]+=value;
		pushdown(node);
		return;
	}
//	if(left==right){
//		tree[node]+=mark[node];
//		tree[node]+=value;
//		mark[node]+=value;
//		return ;
//	}
	pushdown(node);
	update_ar(node*2,left,(left+right)/2,begin,end,value);
	update_ar(node*2+1,(left+right)/2+1,right,begin,end,value);
	update_p(node);
}
//查询区间和
long long query_ar(int node,int left,int right,int begin,int end)
{
	if(left>end||right<begin) return -1; 
	if(left>=begin&&right<=end){
		tree[node]+=mark[node]*(right-left+1);
		pushdown(node);
		return tree[node];
	}
	pushdown(node);
	long long d1=query_ar(node*2,left,(left+right)/2,begin,end);
	long long d2=query_ar(node*2+1,(left+right)/2+1,right,begin,end);
	if(d1<0) return d2;
	if(d2<0) return d1;
	return d1+d2;
} 



int main()
{
	int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){
    	memset(mark,0,sizeof(mark));
    	memset(tree,0,sizeof(tree));
    	for(int i=1;i<=n;i++){
    		scanf("%lld",&num[i]);
		}
		buildtree(1,1,n);
		
//		for(int i=1;i<18;i++){
//			cout<<tree[i]<<" ";
//		}

		int a,b,c;
		while(q--)
		{
			//getchar();
			scanf("%s",qq);
			if(qq[0]=='C'){
			scanf("%d%d%d",&a,&b,&c);
			update_ar(1,1,n,a,b,c);
		}else{
				scanf("%d%d",&a,&b);
				printf("%lld\n",query_ar(1,1,n,a,b));
			}
			
		}
	}
	return 0;
}
