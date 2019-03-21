/*poj2159*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#define ll long long
#define mode 1000000007
#define MAXN  107
#define INF 100000000
#define EPS 0.000000001

using namespace std;
char str1[MAXN];
char str2[MAXN];
char newstr[MAXN];

int se[10]={2, 1, 5, 4, 3, 7, 6, 10, 9, 8};

int flag1[28];
int flag2[28];

int main()
{
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
    //	memset(flag,0,sizeof(flag));
        memset(flag1,0,sizeof(flag1));
        memset(flag2,0,sizeof(flag2));
      	int n=strlen(str1);
      	
      	for(int i=0;i<n;i++){
      		flag1[str1[i]-'A']++;
      		flag2[str2[i]-'A']++;
		  }
		 
		  int markk=1;
		  sort(flag1,flag1+26);
		  sort(flag2,flag2+26);
		 
		  for(int i=0;i<26;i++){
		  	if(flag1[i]!=flag2[i]){
		  		markk=0;
		  		printf("NO\n");
		  		break;
			  }
		  }
		if(markk) printf("YES\n"); 
		str1[0]='\0';
		str2[0]='\0';
		
	}
	return 0;
} 
