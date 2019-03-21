/*sbt的原理就是满足 子树数量 
s[r[t]]>=max(s[r[l[t]]],s[l[l[t]]])
s[l[t]]>=max(s[l[r[t]]],s[r[r[t]]]
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 50007 
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
int s[MAXNUM];
int sb[MAXNUM];
int tree[MAXNUM][2];//tree[node][0]左,tree[node][1]右子树
int cent=0;

void update(int x)
{
	s[x]=s[tree[x][0]]+s[tree[x][1]];
}

void insert(int &x,int key)
{
	if(x==0){
		x=++cent;
		sb[x]=key;
		s[x]=1;
		tree[x][1]=0;
		tree[x][0]=0;
		 
	}else{
		s[x]++;
		insert(tree[x][key>=sb[x]]);
	}
	maintain(x);
}

void ror(int &node)
{
	int temp=node;
	node=tree[node][0];
	tree[node][1]=temp;
	tree[temp][0]=tree[node][1];
	update(temp);
	update(node);
}

void rol(int &node)
{
	int temp=node;
	node=tree[temp][1];
	tree[node][0]=temp;
	tree[temp][1]=tree[node][0];
	update(temp);
	update(node);
}

void maintain(int &node)
{
	if(tree[tree[node][0]][0]>tree[node][1]){
		ror(node);
	}else{
		if(tree[tree[node][0]][1]>tree[node][1]){
			rol(tree[node][0]);
			ror(tree[node][0]);
		}else{
			if(tree[tree[node][1]][1]>tree[node][0]){
				rol(node);
			}else{
				ror(tree[node][1]);
				rol(tree[node][1]);
			}
		}
	}
	maintain(tree[node][0]);
	maintain(tree[node][1]);
	maintain(node);
	
}

int getpre(int &node,int value,int y)
{
	if(value==sb[node]) return y;
	if(sb[node]>value){
		return getpre(tree[node][0],value,y);
	}else
	    return getpre(tree[node][1],value,sb[node]);
}

int getsucc(int &node,int value,int y)
{
	if(value==sb[node]) return y;
	if(sb[node]>value)
	return getsucc(tree[node][1],value,sb[node]);
	else 
	return getsucc(tree[node][1],value,y);
}

void delete_(int &node,int value)//前驱替代 
{
	s[node]--;
	int temp;
	if(value==sb[ndoe]||tree[node][value>=sb[node]]==0){
		temp=sb[node];
		if(!tree[node][0]||!tree[node][1])
		node=tree[node][0]+tree[node][1];//这是什么意思？？ 
		else
		sb[node]=delete_(tree[node][0],k+1);//这个地方，为什么k+1?? 
	}else{
		temp=delete_(tree[node][value>=sb[node]],k);
	}
	return temp;
}

int findi(int &node,int i)//找第i小
{
	int r=s[tree[node][0]]+1;
	if(r==i) return sb[node];
	else if(r<i) return findi(tree[node][1],i-r);
	     else return findi(tree[node][0],i);
} 

int findindex(int node,int value)
{
	if(value>sb[node]) return findindex(tree[node][1],value)+s[tree[node][0]]+1;
	else if(value<sb[node]) return findindex(tree[node][0],value);
	else return s[tree[node][0]]+1;
}

int main()
{

	return 0;
}
