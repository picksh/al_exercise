/*poj-1222 电灯问题
枚举+位运算
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<map>
#define eps 0.000000001
#define ll long long
#define MAXN 507

using namespace std;

char orilight[10];
char light[10];
char re[10];




int getbit(char c,int i)
{
	return (c>>i)&1;
}

void setbit(char & c,int i,int value)
{
    if(value){
		c|=(1<<i);
	}else{
		c&=~(1<<i);
	}
}

void flip(char &c,int i)
{
	c^=(1<<i);
}

void output(int tot)
{
	printf("PUZZLE #%d\n",tot);
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			printf("%d",getbit(re[i],j));
			if(j<5) printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int tot=0;
	while(t--){
		tot++;
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				int s;
				scanf("%d",&s);
				setbit(orilight[i],j,s);
			}
		}
	//	cout<<getbit(orilight[0],1)<<"hello"<<"\n";
            for(int i=0;i<64;i++){
			int switchs=i;//记录开关状态 
			memcpy(light,orilight,sizeof(orilight));
			for(int j=0;j<5;j++){
				re[j]=switchs;
				for(int k=0;k<6;k++){
					if(getbit(switchs,k)){
						flip(light[j],k);
						if(k>0) flip(light[j],k-1);
						if(k<5) flip(light[j],k+1);
					//	if(j<4) flip(light[j+1],k);
					}
				}
				//处理下一行 
				if(j<4){                  /*******这个操作很骚***/ 
					light[j+1]^=switchs;
				}
				switchs=light[j];
			}
			if(light[4]==0){
			//	cout<<re[0]<<" "<<re[1]<<"\n";
				output(tot);
				break;
			}
		}
	}
	return 0;
}
