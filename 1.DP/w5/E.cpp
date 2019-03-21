#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 100007
#define pi 3.1415926

using namespace std;
char num[MAXNUM];
char temp[MAXNUM];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int x;
		int count=0;
		for(int i=0;i<n;i++){
			scanf("%c",&x);
			if(x>temp[count]||count==0)
			temp[count++]=x;
			else {
				int k=lower_bound(temp,x,temp+count)-temp;
				temp[k]=x;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
