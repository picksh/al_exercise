#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstrig>
#include<vector>
#include<queue>
#include<cstdlib>
#define MAXN  10000
#define INF 100000000
#define EPS 0.000000001

using namespace std;
char str[4];
bool v[3];//t,h,d;
double t,h,d;

void init(char w,double num)
{
	switch(w)
	{
		case 'T':{
			t=num;
			v[0]=true;
			break;
		}
		case 'H':{
			v[1]=true;
			h=num;
			break;
		}
		case 'D':{
			v[2]=true;
			d=num;
			break;
		}
	}
}

void getans(int mar)
{
	switch(mar)
	{
		case 0:{
			
			break;
		}
	}
}

int main()
{
	char w;
	double num;
    while(scanf("%c",&w)&&w!='E'){
    	int mar;
    	scanf("%lf",&num);
    	init(w,num);
    	scanf("%c%d",&w,&num);
    	init(w,num);
    	for(int i=0;i<3;i++){
    		if(v[i]){
    			mar=i;break;
			}
		}
		getans(mar);
	}	
}
