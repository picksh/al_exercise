 #include<cstdio>
#include<iostream>
#include<cstdlib>
/*�ⷽ���� x��ai(mod mi)*/ 

/*���񣺸���һ�������Ƶ�λ��n��
��һ��0-2^n-1�����У�
ʹ�����������ͷβ���ڣ��Ķ����Ʊ�ʾ��ֻ��ǡ��һλ��ͬ*/ 

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

