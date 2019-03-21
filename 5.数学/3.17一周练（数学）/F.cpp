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
#define MAXN 1000007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;
int fac[MAXN];
ll x,y;

void init()
{
	fac[1]=1;
	fac[0]=1;
	for(int i=2;i<MAXN;i++){
		fac[i]=(ll)(fac[i-1])*i%mode;
		fac[i]%=mode;
	}
//	for(int i=MAXN-70;i>=MAXN-1000;i--) cout<<fac[i]<<" ";
//	cout<<"\n";
}

//扩欧 

//int extend_gcd(int a,int b,ll &x,ll &y)
//{
//	if(b==0){
//		x=1;y=0;
//		return a;
//	}else{
//		int r=extend_gcd(b,a%b,y,x);
//		y-=x*(a/b);
//		return r;
//	}
// } 
 
 
//费马小定理 
 int quick_pow(ll a,ll b,ll mod)
 {
 	if(b==1) return a%mod;
 	ll ans=quick_pow(a,b/2,mod);
 	if(b&1) return ans*ans*a%mod;
 	else return ans*ans%mod;
  } 
  

 int main()
 {
 	init();
 	int n,m,t;

 	int tot=0;
 	scanf("%d",&t);
 	while(t--){
 		ll ans=0;//要用ll存！！ 
 		tot++;
 		scanf("%d%d",&n,&m);
 	//	extend_gcd(fac[m],mode,x,y);
 	//	cout<<x<<"\n";
 	    x=quick_pow(fac[m],mode-2,mode); 
 		x=(x%mode+mode)%mode;
 	//	cout<<x<<"\n";
 		ans=(ll)(fac[n])*x%mode;
 	//	cout<<ans<<"\n";
 	//	extend_gcd(fac[n-m],mode,x,y);
 		//cout<<x<<"\n";
 		x=quick_pow(fac[n-m],mode-2,mode);
 		x=(x%mode+mode)%mode;
 		ans=ans*x%mode;
 		if(n==0||m==0) 
 		printf("Case %d: 1\n",tot);
 		else
 		printf("Case %d: %lld\n",tot,ans%mode);

 		
	 }
 }
