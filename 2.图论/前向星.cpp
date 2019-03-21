/*前向星
其中edge[i].to表示第i条边的终点,edge[i].next表示与第i条边同起点的下一条边的存储位置,edge[i].w为边权值.
另外还有一个数组head[],它是用来表示以i为起点的第一条边存储的位置,实际上你会发现这里的第一条边存储的位置其实
在以i为起点的所有边的最后输入的那个编号.*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#define MAXN 10000
#define eps 0.00000001
#define INF 1000000000

using namespace std;

struct edge
{
    int nextt;
    int to;
    int w;
}graph[MAXN];

int head[MAXN];
int cnt=0;

void add(int i,int j,int weight)//add一条由i指向j的权值为weight的边
{
    graph[cnt].to=j;
    graph[cnt].w=weight;
    gragh[cnt].nextt=head[i];
    head[i]=cnt++;
}

void traveral(int start)//start为起始的节点，遍历它的所有边
{

    for(int i=head[start];i!=-1;i=graph[i].nextt){

    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){

    }

}
