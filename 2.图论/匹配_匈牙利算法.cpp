/*
����ö����ߵĵ�x�����г���ָ��ĵ�y��
��y֮ǰû�б�ƥ�䣬
��ô��x,y)����һ�ԺϷ���ƥ�䣬
���ǽ�ƥ������һ��
����������ͼ��ԭ��ƥ��y��x��������һ��ƥ�� ��
���ƥ��ɹ�����ô(x,y)�Ϳ�������Ϊһ�ԺϷ���ƥ�䡣
�ݹ� 
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#define MAXN 20007
#define eps 0.00000001
#define INF 0x7fffffff//1000000008

using namespace std;

vector<int> g[MAXN];
int from[MAXN];
bool used[MAXN];

bool match(int x)
{
	for(int i=0;i<g[x].size();i++){
		if(!used[g[x][i]]){
			used[g[x][i]]=true;
			if(from[g[x][i]]==-1||match(from(g[x][i]))){
				from[g[x][i]]=x;
				return true;
			}
		}
	}
	return false;
}

int hungary(int n)
{
	int tot=0;
	memset(from,-1,sizeof(from));
	for(int i=0;i<n;i++){
		memset(used,false,sizeof(used)){
			if(match(i)) tot++;
		}
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%")
		}
	}
}
