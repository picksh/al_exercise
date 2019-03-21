/*最小生成树prim算法
先任意找一个点标记，
然后每次找一条最短的两端分别
为标记和未标记的边加进来，把未标记的点标记上。
即每次加入一条合法的最短的边，每次扩展一个点由未标记为已标记，直至扩展至N个点
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#define MAXN 1007
#define eps 0.00000001
#define INF 1000000000

using namespace std;

vector<pair<int,int> > g[MAXN];
bool v[MAXN];
int dis[MAXN];

int prim(int n)
{
    memset(x,0,sizeof(v));
    int ans=0;
    for(int i=0;i<n;i++) dis[i]=INF;
    dis[0]=0;
    for(int i=0;i<n;i++){
        int mark=-1;
        for(int j=0;j<n;j++){
            if(!v[j]){
                if(mark==-1) mark=j;
                else if(dis[j]<dis[mark]) mark=j;
            }
        }
        if(mark==-1) break;
        v[mark]=true;
        ans+=dis[mark];
        for(int j=0;j<g[mark].size();j+=){
            if(!v[g[mark][j].first){
                int x=g[mark][j].first;
                dis[x]=min(dis[x],g[mark][j].second);
            }
        }
        return ans;
    }

    g.clear();
    return sum;
}



int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){

        printf("%d\n",prim(n));
    }
    return 0;
}
