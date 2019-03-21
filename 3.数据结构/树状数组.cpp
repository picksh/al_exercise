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
#define MAXNUM 50007
#define pi 3.1415926

using namespace std;
int num[MAXNUM];
int tree[MAXNUM];

int lowbit(int x)
{
	return x&(-x);
}

//前缀和般 
void bulidtree(int n)
{
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=lowbit(j)){
			tree[j]+=num[i];
		}
	}
}

void update(int i,int value);
{
	while(i<=n){
		tree[i]+=value;
		i+=lowbit(i);
	}
}

int query(int k)
{
	int sum=0;
	while(k){
		sum+=tree[k];
		k-=lowbit(k);
	}
	return sum;
}

//最大值
void inittree(int n)
{
	memset(tre,0,sizeof(tre));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=lowbit(j)){
			tre[j]=max(tre[j],num[i]);
		}
	}
 } 

void updat(int i,int value)
{
	while(i<=n){
		tre[i]=max(tre[i],value);
		i+=lowbit(i);
	}
}

int quer(int k)
{
	int ans=0;
	while(k){
		ans=max(ans,tre[k]);
		k-=lowbit(k);
	}
}

int main()
{
    int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	initRMQ(n);
//	for(int i=0;i<=n;i++){
//		cout<<lot[i]<<" ";
//	}
	int a,b;
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}	
	return 0;
}
