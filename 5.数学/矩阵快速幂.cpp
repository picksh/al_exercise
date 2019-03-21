#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1000000
#define pi 3.1415926

using namespace std;
long long ansqure[2][2];
const int mod=7;


void muti(long long temp[][2],long long b[][2])
{
	int retemp[2][2];
	memset(retemp,0,sizeof(retemp));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				retemp[i][j]+=(temp[i][k]%mod*b[k][j]%mod)%mod;
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			temp[i][j]=retemp[i][j];
		}
	} 
}

void pow(int len,long long squre[][2] )
{
	memset(ansqure,0,sizeof(ansqure));
	for(int i=0;i<2;i++){
		ansqure[i][i]=1;
	}
	while(len){
		if(len&1)muti(ansqure,squre);
		muti(squre,squre);
		len/=2;
	}
}
 
int main()
{
//	freopen("b.txt","r",stdin);
	long long a,b,n;
	while(scanf("%lld%lld%lld",&a,&b,&n)!=EOF&&a!=0){
    long long squre[2][2]={{a,b},{1,0}};
    //scanf("%d%d",&l,&m);
    if(n<=2)printf("1\n");
    else{
    pow(n-2,squre);
//    for(int i=0;i<2;i++){
//    	for(int j=0;j<2;j++){
//    		cout<<ansqure[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	long long ans=(ansqure[0][0]+ansqure[0][1])%mod;
    printf("%lld\n",ans%mod);
    }
   // memset(squre,0,sizeof(0));
}
	return 0;
}
