/* 51Nod - 1639 

-1��ʱ�����Ρ��������ǾͿ��Ե����ˣ�
���ڼ����Ѿ��� i-1 ��Ь�����һ�����ˣ�������Ϊ��ans[i-1]��
��ô���ڵĵ� i ��Ь����Ҫ�嵽��ǰ���i-1��Ь���У�
������Ӧ����2*(i-1)��2����ΪЬ������ͷ�����Բ��룩��
��������2*(i-1)+1(�����Լ����Ь��)��ans = ans*(i-1)*2.0/(2.0*i-1);
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define ll long long
#define MAXN 100007
#define MAXM 10007
#define pi 3.1415926

using namespace std;

double getans(int x)
{
	//int pre=1;
	double ans=1;
	for(int i=2;i<=x;i++){
		ans=ans*2/(2.0*(i-1)+1)*(i-1);
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lf\n",getans(n));
}
