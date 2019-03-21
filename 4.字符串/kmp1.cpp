#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1000000
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int a[1000007];
int b[10007];
int nextt[10007];

//kmp

void getnext(int n)
{
	int j=0;
	nextt[0]=nextt[1];
	for(int i=0;i<n;i++){
		while(j>0&&a[i]!=a[j]) j=nextt[j];
		if(a[j]==a[i]) j++;
		nextt[i+1]=j;
	}
}

void matchstring(int n,int m)//i是母字符串 
{
	int j=0;
	for(int i=0;i<n;i++){
		while(j>0&&a[i]!=b[j]) j=nextt[j];
		if(a[i]==b[j]) j++;
		if(j==m-1){
			//说明匹配完成了，根据题目修改
			//若求匹配次数,则重新赋值j 
			j=nextt[j]; 
		}
	}
	
}

int main()
{
//	freopen("a.txt","r",stdin);
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(nextt,0,sizeof(nextt));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		//	printf("%d ",a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		//	printf("%d ",b[i]);
		}
	    
	    
	    int i=1,j=0;
	    int temp=0;
	    //i为a的下标，j为b的下标 
	    while(i<=n&&j<m){
	    	if(a[i]==b[j]){
	    		i++;j++;
	    		temp++;
			}else{
				if(nextt[j]!=-1){
					temp=nextt[j];
					j=nextt[j];
				}
				else{
					temp=0;
					i++;
				continue;
				}
		    }
		    if(temp==m)break;
		}
	//	printf("%d %d ",m,temp);
		if(temp==m){
			int k=i-m;
		    printf("%d\n",k);
		}else printf("-1\n");
	}
	return 0;
}
