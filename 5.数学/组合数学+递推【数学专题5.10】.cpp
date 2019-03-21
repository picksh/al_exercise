/* 51Nod - 1639 

-1根时的情形。这样我们就可以递推了，
现在假设已经有 i-1 根鞋带组成一个环了，概率认为是ans[i-1]，
那么现在的第 i 根鞋带就要插到这前面的i-1根鞋带中，
方法数应该是2*(i-1)（2是因为鞋带的两头都可以插入），
总数就是2*(i-1)+1(加上自己这跟鞋带)：ans = ans*(i-1)*2.0/(2.0*i-1);
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
