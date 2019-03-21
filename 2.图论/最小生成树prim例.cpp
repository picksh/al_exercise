/*��С������prim�㷨
��������һ�����ǣ�
Ȼ��ÿ����һ����̵����˷ֱ�
Ϊ��Ǻ�δ��ǵı߼ӽ�������δ��ǵĵ����ϡ�
��ÿ�μ���һ���Ϸ�����̵ıߣ�ÿ����չһ������δ���Ϊ�ѱ�ǣ�ֱ����չ��N����
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

vector<pair<int,int> > g[MAXN];
bool v[MAXN];
int dis[MAXN];

int prim(int n)
{
    memset(v,0,sizeof(v));
    int ans=-1;
    for(int i=1;i<n;i++) dis[i]=INF;
    dis[0]=0;
   // v[0]=true;
    for(int i=0;i<n;i++){
        int mark=-1;
        for(int j=0;j<n;j++){
            if(!v[j]){
                if(mark==-1) mark=j;
                else if(dis[mark]>dis[j]) mark=j;
            }
                //if(mark==-1||dis[mark]>dis[j]) mark=j;
        }
        if(mark==-1) break;
        v[mark]=true;
        ans=max(ans,dis[mark]);
        for(int j=0;j<g[mark].size();j++){
            if(!v[g[mark][j].first]){
                int x=g[mark][j].first;
                dis[x]=min(dis[x],g[mark][j].second);
            }
        }
    }
    for(int i=0;i<n;i++){
        g[i].clear();
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
            g[a-1].push_back(make_pair(b-1,c));
            g[b-1].push_back(make_pair(a-1,c));
        }
        printf("%d\n",prim(n));
    }
    return 0;
}
