/*poj-3903 LISŒ Ã‚ 
*/

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
//char num[MAXNUM];
int temp[MAXNUM];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(temp,-1,sizeof(temp));
		int x;
		int count=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x>temp[count-1]||count==0)
			temp[count++]=x;
			else {
				int k=lower_bound(temp,temp+count,x)-temp;
				temp[k]=x;
			}
		}
		printf("%d\n",count);
		
	}
	return 0;
}
