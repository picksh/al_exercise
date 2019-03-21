#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 310000
#define pi 3.1415926

using namespace std;
//int group[MAXNUM];
long long a[MAXNUM];//a存原始数 
long long b[MAXNUM];//b用来乱搞 
int n,m,u;
int l,r,v,p;

int firpos(int g)
{
	return int(g*sqrt(n)+0.5)-1;
}

int getlen(int g)
{
	return int((g+1)*sqrt(n)+0.5)-int(g*sqrt(n)+0.5);
}

int solm(int lg,int rg,int val)
{
	int ans=0;
	//两边暴力
	int up=firpos(lg+1);
	for(int i=l-1;i<up;i++){
		if(a[i]<val) ans++;
	}
	int down=firpos(rg);
	for(int i=down;i<=r-1;i++){
		if(a[i]<val) ans++;
	}
	//中间直接排序
	int gr=lg+1;
	int pos=firpos(lg+1);//坐标 
	int len=getlen(lg+1);
	while(pos<firpos(rg)){
		sort(b+pos,b+pos+len);
		ans+=lower_bound(b+pos,b+pos+len,val)-(b+pos);
		gr++;
		pos=firpos(gr);
		len=getlen(gr);
	}
	return ans;
}

void update(int posi,int k,int lg,int rg)
{
	a[posi]=u*k/(r-l+1);
	memcpy(b,a,sizeof(a));
//	b[posi]=a[posi];
//	for(int i=firpos(lg+1);i<firpos(rg);i++){
//		b[i]=a[i];
//	}
}

int main()
{
	
//	freopen("d.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&u)!=EOF){
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	//	group[i]=i/sqrt(n);
	} 
	
	while(m--){
		scanf("%d%d%d%d",&l,&r,&v,&p);
		int gl=int((l-1)/sqrt(n)+0.5);
		int gr=int((r-1)/sqrt(n)+0.5);
		int k=solm(gl,gr,v);
		update(p-1,k,gl,gr);
	}
	for(int i=0;i<n;i++) printf("%lld\n",a[i]);
	memset(a,0,sizeof(0));
	memset(b,0,sizeof(0));
}
	return 0;
}
