#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 6007
#define pi 3.1415926

using namespace std;
int dp[MAXNUM][2];
int n,a,b;

struct node{
	int leader;
	//int ha;
	int flag;
}em[MAXNUM];

vector<int> sub[MAXNUM];

int getroot(int posi)
{
	if(em[posi].leader==0) return posi;
	else return getroot(em[posi].leader);
}

void getans(int posi)
{
	int next;
	if(em[posi].flag!=0)
	{
		for(int i=0;i<sub[posi].size();i++){
			next=sub[posi][i];
			getans(next);
			dp[posi][0]+=max(dp[next][1],dp[next][0]);
			dp[posi][1]+=dp[next][0];
		}
	}
}

 
int main()
{
//	freopen("i.txt","r",stdin);
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(em,0,sizeof(em));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			sub[i].clear();
			scanf("%d",&dp[i][1]); 
		}
		int root=0;
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&a,&b); 
			a-=1;
			b-=1;
			sub[b].push_back(a);
			em[b].flag=1;
			em[a].leader=b;
			if(sub[b].size()>sub[root].size()) root=b;
		}
		root=getroot(0);
		getans(root);
//		if(n==1)printf("%d\n",em[0].ha);
//		else
		printf("%d\n",max(dp[root][1],dp[root][0]));
	}
	return 0;
}
