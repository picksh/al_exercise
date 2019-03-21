/*POJ - 3264 */

/*RMQ-���ڳ���Ϊn������A��
�ش�����ѯ��RMQ(A,i,j)(i,j<=n)��
��������A���±���i,j�����С(��ֵ
RMQ������ָ��������ֵ�����⡣*/

/*ST�㷨:online O(nlogn)��Ԥ����O(1)�ػش�ÿ��ѯ�ʡ�*/ 

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<ctime>
#define MAXNUM 50007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;
int h[MAXNUM];
int dpt[MAXNUM][20];
int dps[MAXNUM][20];
//int lot[MAXNUM];

void initRMQ(int n)
{
	for(int i=1;i<=n;i++){
		dpt[i][0]=h[i];
		dps[i][0]=h[i];
	}
	for(int j=1;j<20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dpt[i][j]=max(dpt[i][j-1],dpt[i+(1<<(j-1))][j-1]);
			dps[i][j]=min(dps[i][j-1],dps[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int a,int b)
{
	//int k=lot[b-a+1];
	
	//ֱ�������������ͺ��ˡ���������������� 
	int k=log2(b-a+1.0);
	
	int ans=max(dpt[a][k],dpt[b-(1<<k)+1][k])-min(dps[a][k],dps[b-(1<<k)+1][k]);
	return ans;
}

int main()
{
    int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	initRMQ(n);
	int a,b;
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}	
	return 0;
}
