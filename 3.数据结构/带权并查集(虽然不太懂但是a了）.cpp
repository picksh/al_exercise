#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 50007 
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int father[MAXNUM];//¼ÇÂ¼¸¸½Úµã
int rankk[MAXNUM];
int n,k;

int query(int index)
{
	if(father[index]==index)
	return index;
	else{
	int olk=father[index];
	father[index]=query(olk);
	rankk[index]=(rankk[index]+rankk[olk])%3;
	return father[index];
	}	
}
bool getbool(int x,int y,int flag)
{
	if(x>n||y>n||(x==y&&flag==2))return false;
	int r1=query(x);
	int r2=query(y);
	if(r1!=r2)return true;
	else{
		if(rankk[x]==((flag-1+rankk[y])%3))return true;
		else return false;
	}
}
   
void update(int x,int y,int flag)
{
	int r1=query(x);
	int r2=query(y);
//	if(r1==r2)return;
	father[r1]=r2;
	rankk[r1]=(rankk[y]+flag-1-rankk[x]+3)%3;
}

int main()
{
//	freopen("a.txt","r",stdin);
	scanf("%d%d",&n,&k);
//		memset(father,0,sizeof(father));
//		memset(rankk,0,sizeof(rankk));
		int ans=0;
		int x,y,com;
		for(int i=1;i<=n;i++){
			father[i]=i;
		}
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&com,&x,&y);
				if(getbool(x,y,com))
				update(x,y,com);
				else ans++;
			}
		printf("%d\n",ans);
	return 0;
}
