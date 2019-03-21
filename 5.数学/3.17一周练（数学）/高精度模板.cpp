#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#define MAXN 1000
#define eps 0.00000001
#define lu unsigned long long
#define INF 0x7fffffff//1000000008

using namespace std;
int ten[4]={1,10,100,1000};

struct Bign{
	//d[0]表示当前位数 其余d[i]表示第i位上的数（每4位压成一个万进制数位） 
	int d[MAXN];
	Bign(string s){
		//初始化 
		int len=s.size();
		memset(d,0,sizeof(d));
		d[0]=(len-1)/4+1;
		int j,k;
		for(int i=len-1;i>=0;i--){
			j=(len-i-1)/4+1；
			k=(len-i-1)%4;
			d[j]+=ten[k]*(s[i]-'0'); 
		}
		while(d[0]>1&&d[d[0]]==0) d[0]--;
		Bign(){
			*this=Bign(string("0"));
		}
		
		string tostring(){
			string s("");
			int i,j,temp;
			for(int i=3;i>=1;i--) if(d[d[0]]>=ten[i]) break;
			temp=d[d[0]];
			for(j=i;j>=0;j--){
				s=s+(char)(temp/ten[j]+'0');
				temp%=ten[j];
			}
			for(i=d[0]-1;i>0;i--){
				temp=d[i];
				for(j=3;j>=0;j--){
					s=s+(char)(temp/ten[j]+'0');
					temp%=ten[j];
				}
			}
		}
 
	}
};
