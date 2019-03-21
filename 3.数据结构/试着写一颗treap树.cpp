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
#define MAXN 100007
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;

struct treap{
	int root,treapcnt;
	int key[MAXN];
	int priority[MAXN];
	int cnt[MAXN];//记录重数
	int size[MAXN];
	int child[MAXN][2];
	
	treap(){
		root=0;
		treapcnt=1;
		priority[0]=INF;
		size[0]=0;
	} 
	
	void update(int x)
	{
		size[x]=size[child[x][0]]+size[child[x][1]]+cnt[x];
	}
	void rotate(int &x,int d)
	{
		int y=child[x][d];
		child[x][d]=child[y][1-d];
		child[y][1-d]=x;
		update(x);
		update(y);
		x=y;
	}
	void _insert(int &x,int value)
	{
		if(x){
			if(key[x]==value) cnt[x]++;
		    else{
		    	int t=value>key[x];
		    	_insert(child[x][t],value);
		    	//满足堆序的条件 
		    	if(priority[child[x][t]]<priority[x]) rotate(x,t);
			}
		}else{
			x=treapcnt++;
			key[x]=value;
			child[x][1]=child[x][0]=0;
			priority[x]=rand();
			cnt[x]=1;
		}
		update(x);
	}
	
	void _erase(int &x,int value)//删除值为k的数 
	{
		if(key[x]==value){
			if(cnt[x]>1) cnt[x]--;
			else{
				if(child[x][0]==0&&child[x][1]==0){
					x=0;
					return ;
				}
				int t=priority[child[x][0]>priority[child[x][1]]];
				rotate(x,t);
				_erase(x,value);
			}
		}else{
			_erase(child[x][value>key[x]],value);
		}
		update(x);
	}
	
	int _getkth(int &x,int k)//查找第k大的元素 
	{
		if(k<=size[child[x][0]])
		return _getkth(child[x][0],k);
		else{
			k-=size[child[x][0]]+cnt[x];
			if(k<=0) return key[x];
			else
			return _getkth(child[x][1],k);
		}
		
	}
	
	int _getpre(int x,int value)
	{
		if(key[x]<value){
			if(key[child[x][1]]<value) return _getpre(child[x][1],value);
			else return key[x];
		}else{
			return _getpre(child[x][0],value);
		}
	}
	
	int _getsucc(int x,int value)
	{
		if(key[x]>value){
			if(key[child[x][0]]>value) return _getsucc(child[x][0],value);
			else return key[x];
		}else return _getsucc(child[x][1],value);
	}
	
	int _getrank(int x,int value)
	{
		if(key[x]==value){
			return size[child[x][0]]+1;
		}
		if(key[x]<value){
			return size[child[x][0]]+_getrank(child[x][1],value)+1;
		}else 
		return _getrank(child[x][0],value);
		
	}
	
	void insert(int k)
	{
		_insert(root,k);
	}
	void erase(int k)
	{
		_erase(root,k);
	}
	int getkth(int k)
	{
		return _getkth(root,k);
	}
	int getrank(int x)
	{
		return _getrank(root,x);
	}
	int getpre(int x)
	{
		return _getpre(root,x);
	}
	int getsucc(int x)
	{
		return _getsucc(root,x);
	}
};

int main()
{
	int n,com,num;
	scanf("%d",&n);
	treap T;
	while(n--){
		scanf("%d%d",&com,&num);
		switch(com){
			case 1:{
				T.insert(num);
				break;
			}
			case 2:{
				T.erase(num);
				break;
			}
			case 4:{
				int ans=T.getkth(num);
				printf("%d\n",ans);
				break;
			}
			case 3:{
				int ans=T.getrank(num);
				printf("%d\n",ans);
				break;
			}
			case 5:{
				int ans=T.getpre(num);
				printf("%d\n",ans);
				break;
			}
			case 6:{
				int ans=T.getsucc(num);
				printf("%d\n",ans);
				break;
			}
		}
	}
	return 0;
} 
