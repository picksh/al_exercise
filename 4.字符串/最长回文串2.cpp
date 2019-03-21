#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 110007
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int str[MAXNUM];
int newstr[MAXNUM*2];
int rec[MAXNUM];

void getstr(int n)
{
	newstr[0]=-1;
	newstr[1]=0;
	for(int i=0;i<n;i++){
		newstr[i*2+2]=0;
		newstr[i*2+3]=str[i];
	}
	newstr[2*n+2]=0;
	newstr[2*n+3]=-2;
}

int findmax(int n)
{
	int maxid=0,id=0;
	int ans=1;
	int len=n*2+2;
	for(int i=0;i<len;i++){
		if(maxid>i){
			rec[i]=min(rec[2*id-i],maxid-i);
		}else{
			rec[i]=1;
		}
		while(newstr[i+rec[i]]==newstr[i-rec[i]]&&
		newstr[i+rec[i]]<=newstr[i+rec[i]-2]&&newstr[i-rec[i]]<=newstr[i-rec[i]+2]	)
		rec[i]++;
		if(rec[i]+i>maxid){
			maxid=rec[i]+i;
			id=i;
		}
		ans=max(ans,rec[i]);
	}
	return ans;
}

int main()
{
	freopen("e.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) 
	{
		int n;
		scanf("%d",&n); 
		for(int i=0;i<n;i++){
			scanf("%d",&str[i]);
		}
		getstr(n);
//		for(int i=0;i<2*len+2;i++){
//			printf("%c ",newstr[i]);
//		}
		int ans=findmax(n);
		printf("%d\n",ans-1);
		str[0]='\0';
		newstr[0]='\0';
		rec[0]='\0';
	//	getchar();
	}
	return 0;
}
