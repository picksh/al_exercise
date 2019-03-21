/*如果一个数包含平方因子，那么miu(n) = 0。
例如：miu(4), miu(12), miu(18) = 0。 
如果一个数不包含平方因子，并且有k个不同的质因子，
那么miu(n) = (-1)^k。
例如：miu(2), miu(3), miu(30) = -1,
miu(1), miu(6), miu(10) = 1。 
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

int getmiu(int x)
{
	int temp=x;
	int n=sqrt(x)+1;
	int k=0;
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(temp==1) break;
		if(temp%i==0){
			cnt=0;
			k++;
			while(temp%i==0){
				cnt++;
				temp/=i;
			}
			if(cnt>1){
				cnt=-1;
				break;
			}
		}
	}
	if(cnt<0) return 0;
	if(temp!=1) k++;
	if(k&1) return -1;
	return 1;
}

int main()
{
	int n;
//	initprime();
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",getmiu(n));
	}
 } 
