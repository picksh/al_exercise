/*ǰ����
����edge[i].to��ʾ��i���ߵ��յ�,edge[i].next��ʾ���i����ͬ������һ���ߵĴ洢λ��,edge[i].wΪ��Ȩֵ.
���⻹��һ������head[],����������ʾ��iΪ���ĵ�һ���ߴ洢��λ��,ʵ������ᷢ������ĵ�һ���ߴ洢��λ����ʵ
����iΪ�������бߵ����������Ǹ����.*/

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

void add(int i,int j,int weight)//addһ����iָ��j��ȨֵΪweight�ı�
{
    graph[cnt].to=j;
    graph[cnt].w=weight;
    gragh[cnt].nextt=head[i];
    head[i]=cnt++;
}

void traveral(int start)//startΪ��ʼ�Ľڵ㣬�����������б�
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
