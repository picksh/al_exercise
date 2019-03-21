#include<cstdio>
#include<iostream>
#include<cstdlib>
/*
Euler函数表达通式：euler(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…(1-1/pn),其
中p1,p2……pn为x的所有素因数，x是不为0的整数。
euler(1)=1（唯一和1互质的数就是1本身）。 
·欧拉公式的延伸：一个数的所有质因子之和是euler(n)*n/2。
·解方程组 x三ai(mod mi)
*/ 

#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<ctime>
#define MAXN 1000007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;
int s[MAXN];

//在线做法
//int getouler(int x)
//{
//	int ans=1;
//	int temp=x;
//	int n=sqrt(x)+1;
//	for(int i=2;i<=n;i++){
//		if(temp==1) break;
//		if(temp%i==0){
//			ans=ans/i*(i-1);
//		}
//		while(temp%i==0) temp/i;
//	}
//	if(temp!=1) ans=ans/temp*(temp-1);
//	return ans;
// } 

//筛法求欧拉函数表

void getouler(int n)
{
	s[1]=1;
	for(int i=2;i<n;i++) s[i]=i;
	for(int i=2;i<n;i++){
		if(s[i]==i){
			for(int j=i;j<n;j+=i) s[j]=s[j]/i*(i-1);
		}
	}
 } 

int main()
{
    int n;
    getouler(1000);
    for(int i=5;i<=30;i++){
    	printf("%d ",s[i]);
	}
//	while(scanf("%d",&n)!=EOF){
//		int x;
//		int ans;
//		
//		for(int i=0;i<n;i++){
//			scanf("%d",&x);
//			//a[x]++;
//			if(a[x]>=(n+1)/2) ans=x;
//		}
//
//		printf("%d\n",ans);
//		memset(a,0,sizeof(a));
//	} 
    return 0;
}

