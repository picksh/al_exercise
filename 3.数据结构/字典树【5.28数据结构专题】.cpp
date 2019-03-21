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
#define MAXN 30
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;

int t,n,num;
char com[15];

struct trie{
	trie* child[2];
	trie(){
		memset(child,0,sizeof(child));
	}
}*root;

void insert(int x)
{
	trie* cur=root;
	for(int i=30;i>=0;i--){
		//int k=(x&(i<<1))
		int k=(x&(1<<i))?1:0;
	//	cout<<"i="<<i<<" k="<<k<<"\n";
//		cout<<k<<"\n";
		if(!cur->child[k])
		cur->child[k]=new trie;
		cur=cur->child[k];
	}
}

int getans(int flag,int x)
{
	int ans=x;
	trie* cur=root;
//	cout<<"flag="<<flag;
	for(int i=30;i>=0;i--){
	//	int k=x&(i<<1);
	    int k=(x&(1<<i))?1:0;
	   // cout<<"i="<<i<<"  k^flag="<<(k^flag)<<"\n";
		if(cur->child[k^flag]){
			ans=ans^((k^flag)*(1<<i));
			cur=cur->child[k^flag];
		}else{
			ans=ans^((1<<i)*(1^k^flag));
			cur=cur->child[1^k^flag];
		}
	} 
	return ans;
}

void destroy(trie* cur)
{
   for(int i=0;i<2;i++)
   if(cur->child[i]) destroy(cur->child[i]);
   delete cur;	
}
	
int main()
{
	scanf("%d",&t);
	while(t--){
		root=new trie;
		scanf("%d",&n);
		while(n--){
			scanf("%s%d",com,&num);
			if(com[0]=='i') insert(num);
			else{
				if(com[2]=='i') printf("%d\n",getans(0,num));
				else printf("%d\n",getans(1,num));
			}
		}
		destroy(root);
	}
	return 0;
}
