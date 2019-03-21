#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1010
#define pi 3.1415926

using namespace std;
 
int main()
{
	freopen("c.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		memset(cut,0,sizeof(cut));
		int len=strlen(str);
		w(len);
		getans(0,len-1);
	}
	return 0;
}
