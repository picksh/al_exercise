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
struct binaryheap{
	int posi[MAXNUM],id[MAXNUM],counter,heap[MAXNUM],n;//n表示堆中当前元素的个数，counter表示加入堆中元素的个数 
	//构造一个空堆 
	binaryheap():n(0),counter(0) {}
	//将数组中的元素按顺序插入所构造的堆 
	binaryheap(int array[],int offset):n(0),counter(0){
		for(int i=0;i<offset;i++){
			heap[++n]=array[i];
			id[n]=posi[n]=n;
		}
		//一个有n个节点的完全二叉树的最后一个非叶节点是节点[n/2]，堆的初始化过程就从这个[n/2]节点开始。
		for(int i=n/2;i>=1;i--){
			down(i);
		}
	}
	
	void push(int value)
	{
		heap[++n]=value;
		id[n]=++counter;
		posi[id[n]]=n;
		up[n];
	}
	//出最小（堆顶）->换到底下出去 
	int pop()
	{
		swap(heap[1],heap[n]);
		swap(id[1],id[n--]);
		posi[id[1]]=1;
		down(1);
		return id[n+1];//返回出去的（最小值）插入堆中的次序编号 	
	} 
	
	void change(int i,int value)//修改第i个元素为value 
	{
		heap[posi[i]]=value;
		down(posi[i]);
		up(posi[i]);
	}
	
	void get(int i)
	{
		return heap[posi[i]];
	}
	
	void top()
	{
		return heap[1];
	}
	
	void erase_(int i)//删除第i个元素 
	{
		heap[posi[i]]=-INF;
		up(posi[i]);
		pop();
	}
	
	//与父亲节点比较，若小于父亲节点，则交换。 
	void up(int i)
	{
		int x=heap[i],y=id[i];
		for(j=i/2;j>=1;j/=2){
			if(x<heap[j]){
				id[i]=id[j];
				heap[i]=heap[j];
				posi[id[i]]=i;
				i=j;
			}else break;
		}
		heap[i]=x;
		id[i]=y;
		posi[y]=i;
	}
	//与较小的儿子节点比较，若大于，则交换。 
	void down(int i)
	{
		int x=heap[i],y=id[i];
		for(int j=i*2;j<=n;j*=2){
			j+=j<n&&heap[j]>heap[j+1];
			if(x>heap[j]){
				id[i]=id[j];
				heap[i]=heap[j];
				posi[id[i]]=i;
				i=j;
			}else break;
		}
		id[i]=y;
		heap[i]=x;
		posi[y]=i;
	}
};


int main()
{
	
}
