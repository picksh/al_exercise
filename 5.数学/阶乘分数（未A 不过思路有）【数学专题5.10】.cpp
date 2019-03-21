#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
#define MAXN 100007
#define mode 100000007
using namespace std;

int n; 
int v[MAXN];
int prime[MAXN];
int tot=0;

//先打一个素数表 
void primeinit()
{
	memset(v,true,sizeof(v));
	for(int i=2;i<=n;i++){
		if(v[i]){
			tot++;
			prime[tot]=i;
		}
		for(int j=1;(j<=tot)&&(i*prime[j]<=n);j++){
			v[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}


//快速乘法（取模） 

ll quick_mul(ll a,ll b)
{ 
    ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%mode;
		(a+=a)%mode;
		b/=2; 
    }
    return ans%mode;
}

//快速幂(取模)

ll quick_pow(ll a,ll b)
{
	ll ans=1;
	if(b&1) ans=a%mode;
	while(b){
		ans=ans*ans%mode;
		b>>1;
	}
	return ans%mode;
 } 

ll getprimefactorpow(int x)
{
	int temp=x;
	ll ans=1;
	for(int i=1;i<=tot&&prime[i]<=x;i++){
		int cnt=0;
		while(temp%prime[i]==0){
			cnt++;
			temp/=prime[i];
		}
		ans=quick_mul(ans,cnt+1)%mode; 
	}
	return (ans+ans)%mode;
}

int main()
{
	scanf("%d",&n);
	primeinit();
	ll ans=getprimefactorpow(n);
	printf("%lld",(ans+1)*(quick_mul(2,mode-2)%mode)%mode);
	return 0;
}
