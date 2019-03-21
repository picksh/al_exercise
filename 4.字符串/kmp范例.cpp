/*HDU - 2087 */ 

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
char a[1000007];
char b[10007];
int nextt[10007];



int find_substring()
{
	int ans=0;
	int n=strlen(a);
	int m=strlen(b);
	for(int i=1;i<m;i++){
		int j=i;
		while(j>0){
			j=nextt[j];
			if(a[j]==a[i]){
				nextt[i+1]=j+1;
				break;
			}
		}
	}
	for(int i=0,j=0;i<n;i++){
		if(j<m&&a[i]==b[j]){
			j++;
		}else{
			while(j>0){
				j=nextt[j];
				if(b[j]==a[i]){
					j++;
					break;
				}
			}
		}
		if(j==m) {
			ans++;
			j=0;
		}
	}
	return ans;
}

int main()
{
//	freopen("a.txt","r",stdin);
	while(scanf("%s",a)!=EOF&&a[0]!='#'){
		//scanf("%s",a);
		scanf("%s",b);
		int ans=find_substring();
		printf("%d\n",ans);
		a[0]='\0';
		b[0]='\0';
		memset(nextt,0,sizeof(nextt));
    }
	return 0;
}
