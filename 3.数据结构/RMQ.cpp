#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define EPS (10e-8)
#define MAXNUM 500000
using namespace std;

long long h[MAXNUM];
long long maxX[MAXNUM][MAXNUM];


void in(int n)
{
	for(int i=1;i<n;i++){
		maxX[i][0]=h[i];
	}
	for(int j=1;j<=log(n);++j)
	 for(int i=1;i+(1<<j)-1<=n;++i) 
	    maxX[i][j]=max(maxX[i][j-1],maxX[i+(1<<(j-1))][j-1]);

//	for(int j=1;j<log(n)/log(2);j++){
//		for(int i=0;i<n+1-pow(2,i);i++){
//			maxX[i][j] = max(maxX[i][j-1], maxX[i+pow(2,j-1)][j-1]);
//		}
//	}
}

void RMQ(int i,int j)
{
  int k=log(j-i+1)/log(2);
  printf("%d\n",max(maxX[i][k],maxX[j-(1<<k)+1][k]));
}


int main()
{
	int n,q,a,b;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&h[i]);
		}
		for(int i=0;i<q;i++){
			scanf("%d%d",&a,&b);
			RMQ(a,b);
		}
	}

    return 0;
}
