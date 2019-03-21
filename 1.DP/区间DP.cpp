/*POJ - 1141 */

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
int cut[MAXNUM][MAXNUM];
int cutposi[MAXNUM][MAXNUM];
char str[107];
 
void w(int len)
{
	int temp;
	for(int i=0;i<len;i++) cut[i][i]=1;
	for(int k=1;k<len;k++){
		for(int i=0;i+k<len;i++){
			temp=i+k;
			cut[i][temp]=INF;
			if(str[i]=='('&&str[temp]==')'||str[i]=='['&&str[temp]==']'){
				/*最小增添*/ 
				if(cut[i+1][temp-1]<cut[i][temp])
				cut[i][temp]=cut[i+1][temp-1];
				cutposi[i][temp]=-1;
			}
			/*最优切割位置*/ 
			for(int j=i;j<temp;j++){
				if(cut[i][temp]>cut[i][j]+cut[j+1][temp]){
					cut[i][temp]=cut[i][j]+cut[j+1][temp];
					cutposi[i][temp]=j;
				}
//				cut[i][temp]=min(cut[i][temp],cut[i][j]+cut[j+1][temp]);
//				cutposi[i][temp]=j;
			}
			}
			
		}
}
 
void getans(int i,int j)
{
	if(i>j)return ;
	if(i==j){
		switch(str[i]){
			case'(':
			case')':{
				printf("()");
				break;
			}
			case'[':
			case']':{
				printf("[]");
				break;
			}
		}
	}else {
		if(cutposi[i][j]==-1){
		printf("%c",str[i]);
		getans(i+1,j-1);
		printf("%c",str[j]); 
	}else{
		getans(i,cutposi[i][j]);
		getans(cutposi[i][j]+1,j);
	}	
	}
}
 
int main()
{
//	freopen("c.txt","r",stdin);
	scanf("%s",str);
		memset(cut,0,sizeof(cut));
		int len=strlen(str);
		w(len);
		getans(0,len-1);
		printf("\n");
	return 0;
}
