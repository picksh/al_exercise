/*求(a/b)%p时，因为除法的取余满足分配律，
故当a很大时秒爆ll；
若b与p互质，可求b的乘法逆元，则原式可以改成a*c(%p);*/

//扩欧求逆元
int extend_gcd(int a,int b,int &x,int &y);//a为a,b为mod，x为待求的逆元 
{
	if(b==0){
		x=1;y=0;
		return a;
	}else{
		int r=extend_gcd(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
 } 
 
 //费马小定理求逆元，要求mod为质数,x即为b^(p-2)
 //快速幂
 
 int quick_pow(ll a,ll b,ll mod)
 {
 	if(b==0) return a%mod;
 	ll ans=quick_pow(a,b/2,mod);
 	if(b&1) return ans*ans*a%mod;
 	else return ans*ans%mod;
  } 
  
  
