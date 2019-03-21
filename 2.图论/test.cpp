/*最小生成树pkruskal算法
每次取剩下的边权最小的边，如果加上这条边以后图中
出现了一个环（这个可以通过并查集维护），
则破坏了生成树的性质，就不选这条边。
依次进行直到整张图出现一棵生成树为止
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

int father[MAXN];

struct edge
{
    int x,y,w;
    edge(int x=0,int y=0,int w=0):x(x),y(y),w(w){}
}e[MAXN];

bool cmp(edge a,edge b)
{
   return a.w<b.w;
}

int getfather(int x)
{
    if(x==father[x]) return x;
    else return getfather(father[x]);
}

int kruskal(int n,int m)
{
    memset(e,0,sizeof(0));
    sort(e,e+m,cmp);
    int ans=-1;
    int cnt=n;
    for(int i=0;i<n;i++) father[i]=i;
    for(int i=0;i<m;i++){
        int t1=getfather(e[i].x);
        int t2=getfather(e[i].y);
        if(t1!=t2){
            father[t1]=t2;
           // ans+=e[i].w;
            ans=max(ans,e[i].w);
            cnt--;
            if(cnt==1) break;
        }
    }
    return ans;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int a,b,c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            e[i].x=a-1;
            e[i].y=b-1;
            e[i].w=c;
        }
        printf("%d\n",kruskal(n,m));
    }
    return 0;
}
