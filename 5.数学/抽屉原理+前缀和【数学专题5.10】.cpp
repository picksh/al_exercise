/* 51nod-1103 N的倍数 （抽屉原理）
把前缀和求出并对N取模，任意等于0则符合要求，
或者任意两个sum[i]=sum[j]，则[i,j]内的数的和都满足这个条件。
N个数对N取模，相当于N个抽屉，则至少有一个sum[i]等于0，
或者一对儿sum[i]==sum[j]（可以理解为sum[i]-sum[j]==0）。
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
#define MAXN 50007
#define MAXM 10007
#define pi 3.1415926

using namespace std;

int a[MAXN];
int sum[MAXN];

int n;
int main()
{
	scanf("%d",&n);
//	int flag=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]%n==0){
			printf("1\n%d\n",a[i]);
			//flag=1;
			return 0;
		}
	}
	sum[0]=a[0]%n;
	for(int i=1;i<n;i++){
		sum[i]=(sum[i-1]+a[i]%n)%n;
		if(sum[i]==0){
			printf("%d\n",i+1);
			for(int j=0;j<=i;j++){
				printf("%d\n",a[j]);
			}
			return 0;
		}
	}
	int begin=-1;
	int end=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sum[i]==sum[j]){
				begin=i;
				end=j;
				break;
			}
		}
		if(end!=-1&&begin!=-1) break;
	}
	if(end==-1) printf("No Solution\n");
	else{
		printf("%d\n",end-begin);
		for(int i=begin+1;i<=end;i++){
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
