/*×ÖµäÊ÷
poj-1056 
*/ 

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define MAXN 107
#define MAXM 10007
#define pi 3.1415926
#define cha 26
using namespace std;
char str[12];

//struct trie{
	int tot,root;
	int child[MAXN][2];
	bool flag[MAXN];
	
	void init(){
		memset(child[0],0,sizeof(child[1]));
		flag[0]=false;
		root=tot=0;
	}
	void insert()
	{
	//	int begin=1;
		int *cur=&root;
		for(char*p=str;*p;p++){
			cur=&child[*cur][*p-'0'];
			if(*cur==0){
				//begin=0
				*cur=++tot;
				memset(child[tot],0,sizeof(child[tot]));
			//	flag[tot]=false;
			}
			//if(!begin&&flag[tot])
			flag[*cur]=false;
			//begin=0;
		}
		if(!child[*cur][0]&&!child[*cur][1])
		flag[*cur]=true;
	}
	
	int query()
	{
		int ans=0;
		for(int i=0;i<=tot;i++){
			if(flag[i]==true) ans++;
		}
		return ans;
	}
//};

int main()
{
	int n=0;
	while(scanf("%s",str)!=EOF){
		n++;
    	int count=0;
    	init();
		insert();
    	count++;
    	str[0]='\0';
    	while(scanf("%s",str)&&str[0]!='9')
    	{
    		insert();
    		count++;
    		str[0]='\0';
		
    	}
    	int mark=query();
    	if(count==mark) printf("Set %d is immediately decodable\n",n);
    	else printf("Set %d is not immediately decodable\n",n);
    	memset(flag,0,sizeof(flag));
    	}
    	
    return 0;
}
