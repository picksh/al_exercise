#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1000000
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
char word[11];

struct tree{
	tree* alp[26];
	int sum;
};
void buildtree(tree* node)
{
	int len=strlen(word);
	tree* p=node;
	int id;
	for(int i=0;i<len;i++){
		id=word[i]-'a';
		if(p->alp[id]==NULL){
		//	p->sum=1;
			tree* q=new tree;
			for(int j=0;j<26;j++){
				q->alp[j]=NULL;
			}
			p->alp[id]=q;
			p=q;
			p->sum=1;
        }else {
//        	p->sum++;
//        	p=p->alp[id];
        	p=p->alp[id];
            p->sum++;
		}
	}
}				
int search_(tree*node)
{
	int ans=0;
	int id;
	tree* p=node;
	int len=strlen(word);
	for(int i=0;i<len;i++){
		id=word[i]-'a';
		if(p->alp[id]!=NULL){
			//ans=p->sum;
			p=p->alp[id];
		}else return 0;
	}
	return p->sum;
}

void cutree(tree* node)
{
	tree* p=node;
	for(int i=0;i<26;i++){
		if(p->alp[i]!=NULL)
		cutree(p->alp[i]);
	}
	delete p;
}
int main()
{
//	freopen("f.txt","r",stdin);
	tree* root=new tree;
	for(int i=0;i<26;i++){
		root->alp[i]=NULL;
	}
	while(gets(word)&&word[0]!='\0'){
		buildtree(root);
		word[0]='\0';
	}
	while(scanf("%s",word)!=EOF){
	//	cout<<word<<"\n";
		int ans=search_(root);
		printf("%d\n",ans);
	}
	cutree(root);
}
