/*poj-2887
1.将一个字符插入到某个位置的前面
2.询问当前位置的字符

o(根号n) 
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
#define MAXN 5007
#define MAXM 1000007
#define pi 3.1415926
#define cha 26
//#define m 
using namespace std;
const int m=1007;

struct data{
	int s;
	char a[m*2+5];
	data *nextt;
};
data* root;

char str[MAXM];
int len;


void init()
{
	if(len==0) return;
	int tot=0;
	root=new(data);
	root->nextt=NULL;
	root->s=0;
	data* k=root;
	for(int i=0;i<len;i++){
		k->s++;
		k->a[++tot]=str[i];
		if(k->s==m){
			data *t=new(data);
			k->nextt=t;
			t->s=0;
			t->nextt=NULL;
			tot=0;
			k=t;
		}
	}
	
}


void _insert(int posi,char w)
{
	int temp=posi;
	if(posi>len) posi=len;
	if(root==NULL){
		root=new(data);
		root->s=1;
		root->nextt=NULL;
		root->a[1]=w;
	}else{
		data *k=root;
		while(posi>k->s&&k->nextt!=NULL)
		{
			posi-=k->s;
			k=k->nextt; 
		}
		k->s++;
		if(temp<=len){
			memcpy(k->a+posi+1,k->a+posi,sizeof(int)*(k->s-posi+1));
		    k->a[posi]=w;	
		}else{
			k->a[posi+1]=w;
		}
		if(k->s==2*m){
			data *t=new(data);
			t->nextt=k->nextt;
			k->nextt=t;
			memcpy(t->a+1,k->a+m+1,sizeof(int)*m);
			t->s=k->s=m; 
		}
	}
} 

char query(int posi)
{
	data* k=root;
	while(posi>k->s&&k->nextt!=NULL){
		posi-=k->s;
		k=k->nextt;
	}
	return k->a[posi];
}

void del(int posi)
{
	data *k=root;
	while(posi>k->s&&k->nextt!=NULL){
		posi-=k->s;
		k=k->nextt;
	}
	memcpy(k->a+posi,k->a+posi+1,sizeof(int)*(k->s-posi));
	k->s--;
}

void end_(data* k)
{
	if(k->nextt!=NULL){
		end_(k->nextt);
	}
	delete(k);
}

int main()
{
//	root=NULL;
	int q,posi;
	char com[2],word[2];
	scanf("%s%d",str,&q);
    len=strlen(str);
    init();
 
	while(q--){
		scanf("%s",com);
		if(com[0]=='I'){
			
			scanf("%s%d",word,&posi);
			//if(posi>len)
			_insert(posi,word[0]);
			len++;
		}else{
			scanf("%d",&posi);
			//cout<<posi<<" ";
			printf("%c\n",query(posi));
		}
	}
	end_(root);
	return 0;
}

