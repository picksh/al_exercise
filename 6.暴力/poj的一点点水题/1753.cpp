/*poj1753*/

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

char chess[4][4];
int ans=-1;
int step;
int flag;

bool check()
{
	char flag=chess[0][0];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(chess[i][j]!=flag) return false;
		}
	}
	return true;
}

void flip(int x,int y)
{
	if(chess[x][y]=='w') chess[x][y]='b';
	else chess[x][y]='w';
}


void getans(int x,int y,int deep)
{
	if(step==deep){
		flag=check();
		if(flag) return;
	}
	
    	if(x<3) flip(x+1,y);
    	if(y<3) flip(x,y+1);
    	if(x>0) flip(x-1,y);
    	if(y>0) flip(x,y-1);
    if(x==3&&y==3) return;
		else{
			if(x==3) getans(0,y+1,deep+1);
	    	else getans(x+1,y,deep+1);
		}
		if(x<3) flip(x+1,y);
    	if(y<3) flip(x,y+1);
    	if(x>0) flip(x-1,y);
    	if(y>0) flip(x,y-1);
    	
    	if(x==3) getans(0,y+1,deep);
		else getans(x+1,y,deep);
	
}

//void getans(int x,int y,int turnamount)
//{
//	if(check()){
//		ans=turnamount;
//		return;
//	}
//		if(x<3) flip(x+1,y);
//    	if(y<3) flip(x,y+1);
//    	if(x>0) flip(x-1,y);
//    	if(y>0) flip(x,y-1);
//
//		if(x==3&&y==3) return;
//		else{
//			if(x==3) getans(0,y+1,turnamount+1);
//	    	else getans(x+1,y,turnamount+1);
//		}
//	
//    	if(x<3) flip(x+1,y);
//    	if(y<3) flip(x,y+1);
//    	if(x>0) flip(x-1,y);
//    	if(y>0) flip(x,y-1);
//    	
//    	if(x==3) getans(0,y+1,turnamount);
//		else getans(x+1,y,turnamount);
//	
//}

int main()
{
	for(int i=0;i<4;i++){
		scanf("%s",chess[i]);
	}
	
	for(step=0;step<16;step++){
		getans(0,0,0);
		if(flag) break;
	}
	if(flag)
	printf("%d\n",step);
	else printf("Impossible\n");
	
}
