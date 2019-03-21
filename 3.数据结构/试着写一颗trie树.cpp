/*字典树*/ 

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define MAXN 107
#define MAXM 10007
#define pi 3.1415926
#define cha 26
using namespace std;
struct trie{
	int tot,root;
	int child[MAXN][cha];//child[i][j]代表以i为根的子树，字符j代表的边连向哪一个节点。若=0，则没有对应的节点
	bool flag[MAXNUM];
	trie()
	{
		memset(child[1],0,sizeof(child[1]));
		flag[1]=false;
		root=tot=1;
	}
	void insert(const char*str)
	{
		int *cur=&root;
		for(const char*p=str;*p;p++){
			cur=&child[*cur][*p-'a'];
			if(*cur==0){
				*cur=++tot;
				memset(child[*cur],0,sizeof(child[*cur]));
				flag[tot]=false;
			}
		} 
	}
	bool query(const char *str)
	{
		int *cur=&root;
		for(const char* p=str;*p&&*cur;p++){
			cur=&child[*cur][*p-'a'];
		}
		return (*cur&&flag[*cur]);
	}
};

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		init(n,m);
		dij(n); 
		printf("%d\n",dis[n-1]);
	}
	return 0;
}
