#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
const int N=10000;

struct oi{
	char o;
	int fa;
}oil[N][N];

int di[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int m,n;

void dfs(int sm,int sn)//sm为行，sn为列 
{
	int flag=0;
	oil[sm][sn].fa=1;
	if(sm<0||sm>=m-1||sn<0||sn>=n-1)return;
	for(int i=0;i<8;i++){	
		if(oil[sm+di[i][1]][sn+di[i][0]].fa==1||sm+di[i][1]<0||sm+di[i][1]>m-1||sn+di[i][0]<0||sn+di[i][0]>n-1)continue;
		if(oil[sm+di[i][1]][sn+di[i][0]].o=='@'){
		    flag=1;
			dfs(sm+di[i][1],sn+di[i][0]);
		}
	}
	if(!flag)return;
}

int main()
{
	scanf("%d%d ",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%c",&oil[i][j].o); 
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%c",oil[i][j].o); 
		}
		cout<<"\n";
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(oil[i][j].o=='@'&&!oil[i][j].fa)
			{dfs(i,j);ans++;}
		}
	}
	printf("%d\n",ans);
	return 0;
 } 
