/*
依次枚举左边的点x的所有出边指向的点y，
若y之前没有被匹配，
那么（x,y)就是一对合法的匹配，
我们将匹配数加一，
否则我们试图给原来匹配y的x‘重新找一个匹配 ，
如果匹配成功，那么(x,y)就可以新增为一对合法的匹配。
递归 
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
