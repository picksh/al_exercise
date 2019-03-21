/*POJ - 3264 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 10000000
#define MAXNUM 50007
#define pi 3.1415926

using namespace std;
int tree[MAXNUM*4];
int num[MAXNUM];


//��¼����� 
void buildtree(int node,int begin,int end)
{
	if(begin==end){
		tree[node]=num[begin];
		return;
	}else{
		buildtree(node*2,begin,(begin+end)/2);
		buildtree(node*2+1,(begin+end)/2+1,end);
	}
	tree[node]=tree[node*2]+tree[node*2+1];

}
//��������� 
int query(int noede,int left,int right,int begin,int end)//left,rightΪ��ǰ����;begin,endΪ�������� 
{
	if(left>end||right<begin) return -1;//���Ҫ�жϵģ������� 
	if(left>=begin&&right<=end){
		tree[node];
		return tree[node];
	}
	int d1=query(node*2,left,(right+left)/2,begin,end);
	int d2=query(node*2+1,(right+left)/2+1,right,begin,end);
	if(d1==-1) return d2;
	if(d2==-1) return d1;
	return d1+d2;
}
//������� 
void update(int node,int left,int right,int i,int value)
{
	if(left==right){
		tree[node]+=value;
		return;
	}
	int mid=(right+left)/2;
	if(i<=mid) query(node*2,left,mid,i,value);
	else query(node*2+1,mid+1,right,i,value);
	tree[node]+=value;
}

//�����������ֵ
int findmax(int node,int left,int right,int begin,int end)
{
	if(left>end||right<begin) return -1;
	int temp=0;
	if(left>=begin&&right<=end){
		return tree[node];
	}
	temp=max(temp,query(node*2,left,(right+left)/2,begin,end));
	temp=max(temp,query(node*2+1,(right+left)/2+1,right,begin,end));
	
	return temp;
}

//�߶����������(�ͣ� 

mark[MAXNUM*4];

void pushdown(int node)
{
	if(mark[node]){
		mark[node*2]=mark[node];
	    mark[node*2+1]=mark[node];
	    mark[node]=0;//j�Ǻ����´��ݺ�ǵò������� 
	}
	return;
}

void update_p(int node)
{
	tree[node]=tree[node*2]+tree[node*2+1];
}

void update_ar(int node,int left,int right,int begin,int end,int value)//left,rightΪ��ǰ���䣬begin,endΪ���������䡣 
{
	if(left>end||right<begin) return; 
	if(left>=begin&&right<=end){
		tree[node]+=value*(right-left+1);
		tree[node]+=mark[node]*(right-left+1);
		mark[node]+=value;
		return;
	}
	if(left==right){
		tree[node]+=mark[node];
		tree[node]+=value;
		mark[node]+=value;
		return ;
	}
	pushdown(node);
	query(node*2,left,(left+right)/2,begin,end,value);
	query(node*2+1,(left+right)/2+1,right,begin,end,value);
	update(node);
}
//��ѯ�����
int query_ar(int node,int left,int right,int begin,int end)
{
	if(left>end||right<begin) return -1; 
	if(left>=begin&&right<=end){
		return tree[node];
	}
	pushdown(node);
	int d1=query(node*2,left,(left+right)/2,begin,end);
	int d2=query(node*2+1,(left+right)/2+1,right,begin,end);
	if(d1<0) return d2;
	if(d2<0) return d1;
	return d1+d2;
} 

 

int main()
{
    
	return 0;
}
