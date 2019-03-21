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
char str[MAXNUM];
char newstr[MAXNUM*2];
int rec[MAXNUM*2];

void getstr(int n)
{
	newstr[0]='&';
	newstr[1]='^';
	newstr[2*n]='#';
	for(int i=0;i<n;i++){
		newstr[i*2+2]='#';
		newstr[i*2+3]=str[i];
	}
	newstr[2*n+2]='#';
	newstr[2*n+3]='\0';
}

int findmax(int n,int &id)
{
	int maxid=0;
	int ans=1;
	int len=n*2+2;
	for(int i=0;i<len;i++){
		if(maxid>i){
			rec[i]=min(rec[2*id-i],maxid-i);
		}else{
			rec[i]=1;
		}
		while(newstr[i+rec[i]]==newstr[i-rec[i]])
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
//	freopen("d.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		int len=strlen(str);
		getstr(len);
//		for(int i=0;i<2*len+2;i++){
//			printf("%c ",newstr[i]);
//		}
        int posi=0;
		int ans=findmax(len,posi);
		printf("%d\n",ans-1);
		int len2=strlen(newstr);
		for(int i=0;i<len;i++) cout<<str[i]<<" "; 
		str[0]='\0';
		newstr[0]='\0';
		rec[0]='\0';
	//	getchar();
	}
	return 0;
}
