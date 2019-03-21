#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#define MAXN 1007
#define EPS 0.0000000001
#define INF 100000000

using namespace std;
int sg[MANX];
int op[3]={1,3,4}//假设就三种操作 取1或3或4 
bool temp[3];

void getsg(int n)
{
	for(int i=0;i<n;i++){
		memset(temp,0,sizeof(temp));
		for(int j=0;j<3;j++) temp[s[i-op[j]]]=true;
		for(int j=0;j<3;j++){
			if(temp[j]==0)
		}
		
		
	}
}

int main()
{
	
	printf("%d\n",ans);
	return 0;
}
