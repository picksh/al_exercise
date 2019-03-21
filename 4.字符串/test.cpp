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
			p->sum=1;
			tree* q=new tree;
			for(int j=0;j<26;j++){
				q->alp[i]=NULL;
			}
			p->alp[word[0]-'a']=q;
			p=q;
        }else {
        	p->sum++;
        	p=p->alp[word[0]-'a'];
		}
	}
}				
int search_(tree*node)
{
	int ans=0;
	tree* p=node;
	int len=strlen(word);
	for(int i=0;i<len;i++){
		if(p->alp[word[i]-'a']!=NULL){
			ans=p->sum;
			p=p->alp[word[0]-'a'];
		}else return 0;
	}
	return ans;
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
	freopen("f.txt","r",stdin);
	tree* root=new tree;
	for(int i=0;i<26;i++){
		root->alp[i]=NULL;
	}
	while(scanf("%s",word)&&word[0]!='\0'){
		buildtree(root);
		word[0]='\0';
	}
	while(scanf("%s",word)!=EOF){
		int ans=search_(root);
		printf("%d\n",ans);
	}
	cutree(root);
}
