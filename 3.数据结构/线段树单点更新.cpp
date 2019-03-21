/*HDU - 1754 */
/*POJ - 3264 */
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
int tree[MAXNUM*4];
int num[MAXNUM];



void buildtree(int node,int begin,int end)
{
	if(begin==end){
		tree[node]=num[begin];
		return;
	}else{
		buildtree(node*2,begin,(begin+end)/2);
		buildtree(node*2+1,(begin+end)/2+1,end);
	}
	tree[node]=max(tree[node*2],tree[node*2+1]);

}

//单点更新 
void update(int node,int left,int right,int i,int value)
{
	if(left==right){
		tree[node]=value;
		return;
	}
	int mid=(right+left)/2;
	if(i<=mid) update(node*2,left,mid,i,value);
	else update(node*2+1,mid+1,right,i,value);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

//查找区间最大值
int findmax(int node,int left,int right,int begin,int end)
{
	if(left>end||right<begin) return -1;
	if(left>=begin&&right<=end){
		return tree[node];
	}
	int temp=0;
	temp=max(temp,findmax(node*2,left,(right+left)/2,begin,end));
	temp=max(temp,findmax(node*2+1,(right+left)/2+1,right,begin,end));
	
	return temp;
}

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
    	for(int i=1;i<=n;i++){
    		scanf("%d",&num[i]);
		}
		buildtree(1,1,n);
	//	cout<<tree[1]<<"\n";
		char c;
		int a,b;
		for(int i=0;i<m;i++){
			getchar();
			scanf("%c%d%d",&c,&a,&b);
			if(c=='Q')
			printf("%d\n",findmax(1,1,n,a,b));
			else update(1,1,n,a,b);
		}
		memset(tree,0,sizeof(tree));
	}
	return 0;
} 
