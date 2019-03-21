#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#define MAXN 5000006
#define eps 0.00000001
#define INF 0x7fffffff//1000000008


using namespace std;
const int las=5000001;
unsigned long long phi[MAXN];
//int mindiv[MAXN];
//long long sum[MAXN];
//int temp=0;

void getphi()
{
	memset(phi,0,sizeof(phi));
	phi[1]=1;
	for(int i=2;i<las&&i*i;i++){
		if(!phi[i]){
			for(int j=i;j<las;j+=i){
				if(!phi[j])
				phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	} 
//    for(int i=2;i<las;i++){
//        mindiv[i]=i;
//    }
//    for(int i=2;i<las&&i*i<las;i++){
//        if(mindiv[i]==i){
//        	//temp++;
//            for(int j=i*i;j<las;j+=i){
//                mindiv[j]=i;
//            }
//        }
//    }
//    phi[1]=1;
//    for(int i=2;i<las;i++){
//        phi[i]=phi[i/mindiv[i]];
//        if(i/mindiv[i]%mindiv[i]==0) phi[i]*=mindiv[i];
//        else phi[i]*=mindiv[i]-1;
//    }
 
}

void getpre()
{
   // int sum[1]=1;
    for(int i=2;i<las;i++){
        phi[i]=phi[i-1]+phi[i]*phi[i];
    }
}

int main()
{
    int t,n,m;
    getphi();
    getpre();
    scanf("%d",&t);
    int tot=0;
    while(t--){
    	tot++;
        scanf("%d%d",&n,&m);
        unsigned long long ans=phi[m]-phi[n-1];
        printf("Case %d: %llu\n",tot,ans);
    }
    return 0;
}
