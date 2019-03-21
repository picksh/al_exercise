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
char a[1007];
char b[1007];
int nextt[1007];

int main()
{
	freopen("b.txt","r",stdin);
	while(scanf("%s",a)!=EOF&&a[0]!='#'){
		scanf("%s",b);
		int ans=0;
		int len1=strlen(a);
		int len2=strlen(b);
		nextt[0]=-1;
		nextt[1]=0;
		for(int i=2;i<len2;i++){
			int j=i-1;
			while(j!=-1&&b[i-1]!=b[nextt[j]])
				j=nextt[j];
			if(j==-1)nextt[i]=0;
			else
			nextt[i]=nextt[j]+1;
		}
		int i=0,j=0;
	    int temp=0;
		while(i<len1&&j<len2){
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
		    if(temp==len2){
		    	ans++;
		    	temp=0;
		    	j=0;
			}
		}
		printf("%d\n",ans);
		a[0]='\0';
		b[0]='\0';
		memset(nextt,0,sizeof(nextt));	
	}
	return 0;
}
