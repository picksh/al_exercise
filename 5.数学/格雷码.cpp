 #include<cstdio>
#include<iostream>
#include<cstdlib>
/*解方程组 x三ai(mod mi)*/ 

/*任务：给定一个二进制的位数n，
求一个0-2^n-1的排列，
使相邻两项（包括头尾相邻）的二进制表示中只有恰好一位不同*/ 

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
vector<int> gray(int n)
{
	vector<int> res;
	res.clear();
	for(int i=0;i<(1<<n);i++){
		res.push_back(i^(i>>1));
	} 
	return res;
}


int main()
{
    int n;
	while(scanf("%d",&n)!=EOF){
		int x;
		int ans;
		
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[x]++;
			if(a[x]>=(n+1)/2) ans=x;
		}

		printf("%d\n",ans);
		memset(a,0,sizeof(a));
	} 
    return 0;
}

