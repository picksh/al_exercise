#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#define MAXN 10007
#define eps 0.00000001
#define lu unsigned long long
#define INF 0x7fffffff//1000000008

using namespace std;

int coun[MAXN];
int ans[MAXN];
int len;

int quick_pow(int a,int b)
{
	if(b==1) return a;
	int ans=quick_pow(a,b/2);
	if(b&1) return ans*ans*a;
	else return ans*ans;
	
}

void mul(int x)
{
	int y=0;
	for(int i=0;i<len;i++){
		ans[i]=y+ans[i]*x;
		y=ans[i]/10;
		ans[i]%=10;
	}

	while(y){
		ans[len]=y%10;
		y/=10;
		len++;
	}
}

int main()
{
//	for(int i=1;i<=10;i++)
//	cout<<quick_pow(2,i)<<" ";
	
	int t,n,x;
	int tot=0;
	scanf("%d",&t); 
	while(t--){
		memset(ans,0,sizeof(ans));
		memset(coun,0,sizeof(coun));
		tot++;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			for(int j=2;j<=x;j++){
				int cnt=0;
				if(x%j==0){
					while(x%j==0){
						cnt++;
						x/=j;
					}
					coun[j]=max(coun[j],cnt);
					if(x==1) break;
				}
			}
		}
		len=1;
		ans[0]=1;
		for(int i=2;i<MAXN;i++){
			if(coun[i]){
				int m=quick_pow(i,coun[i]);
				mul(m);
			}
		}
		printf("Case %d: ",tot);
		for(int i=len-1;i>=0;i--){
			printf("%d",ans[i]); 
		}
		printf("\n");
	}
}
