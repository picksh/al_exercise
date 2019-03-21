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
#define MAXNUM 50007
#define pi 3.1415926

using namespace std;
int sta[MAXNUM];//0ͬ�࣬1�����ڵ�ԣ�2�Ը��ڵ� 
int fa[MAXNUM];

void init(int n)
{
	for(int i=0;i<=n;i++){
		sta[i]=0;
		fa[i]=i;
	}
}

int findad(int x)
{
	if(fa[x]==x) return x;
	int y=findad(fa[x]);
	sta[x]=(sta[x]+sta[fa[x]])%3;//�������������� 
	return fa[x]=y;
	
}

int update(int type,int x,int y)
{
	int y1=findad(y);
	int x1=findad(x);
	if(y1==x1){
		if((sta[x]-sta[y]+3)%3==type-1)//���ǿ����������� 
		return 0;
		else return 1;
	}
	fa[x1]=y1;
	sta[x]=(type-sta[x]+sta[y]+3-1)%3;//���ǿ��������� 
	return 0;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
		int type,x,y;
		int ans=0;
		init(n);
		for(int i=0;i<k;i++){
			scanf("%d%d%d",&type,&x,&y);
			if(x>n||y>n) ans++;
			else{
				if(x==y&&type==2) ans++;
				else ans+=update(type,x,y);
			}
		}
		printf("%d\n",ans);
	return 0;
}

