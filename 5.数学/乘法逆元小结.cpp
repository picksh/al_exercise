/*��(a/b)%pʱ����Ϊ������ȡ����������ɣ�
�ʵ�a�ܴ�ʱ�뱬ll��
��b��p���ʣ�����b�ĳ˷���Ԫ����ԭʽ���Ըĳ�a*c(%p);*/

//��ŷ����Ԫ
int extend_gcd(int a,int b,int &x,int &y);//aΪa,bΪmod��xΪ�������Ԫ 
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
 
 //����С��������Ԫ��Ҫ��modΪ����,x��Ϊb^(p-2)
 //������
 
 int quick_pow(ll a,ll b,ll mod)
 {
 	if(b==0) return a%mod;
 	ll ans=quick_pow(a,b/2,mod);
 	if(b&1) return ans*ans*a%mod;
 	else return ans*ans%mod;
  } 
  
  
