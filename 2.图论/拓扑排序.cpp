/*拓扑排序 poj-2367
用一个队列实现，把先把入度为0的点放入队列，
然后考虑不断在图中删除队列中的点，
每次删除一个点会产生一些新的入度为0的点，把这些点插入队列*/

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

vector<int> g[MAXN];
int du[MAXN];
int L[MAXN];
int cnt;//记录结果

bool toposort(int n)
{
    memset(du,0,sizeof(du));
    memset(L,0,sizeof(L));
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            du[g[i][j]]++;
        }
    }
//    int tot=0;
    queue <int> q;
    for(int i=1;i<=n;i++){
        if(!du[i]) q.push(i);
    }
    while(!q.empty()){
        int start=q.front();
        q.pop();
        L[cnt++]=start;
        for(int i=0;i<g[start].size();i++){
            int x=g[start][i];
            du[x]--;
            if(!du[x]) q.push(x);
        }
    }
        //for(int i=0;i<n;i++){
          //  if(!du[i]) q.push(i);
       // }
    cnt--;
    if(cnt==n) return 1;//无环
    return 0;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
            int temp;
            for(int i=1;i<=n;i++){
                while(scanf("%d",&temp)&&temp!=0){
                    g[i].push_back(temp);
                }
            }
            toposort(n);
            for(int i=0;i<n;i++){
                printf("%d ",L[i]);
            }
    }
    return 0;
}
