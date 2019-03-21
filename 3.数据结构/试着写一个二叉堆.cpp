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
	int posi[MAXNUM],id[MAXNUM],counter,heap[MAXNUM],n;//n��ʾ���е�ǰԪ�صĸ�����counter��ʾ�������Ԫ�صĸ��� 
	//����һ���ն� 
	binaryheap():n(0),counter(0) {}
	//�������е�Ԫ�ذ�˳�����������Ķ� 
	binaryheap(int array[],int offset):n(0),counter(0){
		for(int i=0;i<offset;i++){
			heap[++n]=array[i];
			id[n]=posi[n]=n;
		}
		//һ����n���ڵ����ȫ�����������һ����Ҷ�ڵ��ǽڵ�[n/2]���ѵĳ�ʼ�����̾ʹ����[n/2]�ڵ㿪ʼ��
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
	//����С���Ѷ���->�������³�ȥ 
	int pop()
	{
		swap(heap[1],heap[n]);
		swap(id[1],id[n--]);
		posi[id[1]]=1;
		down(1);
		return id[n+1];//���س�ȥ�ģ���Сֵ��������еĴ����� 	
	} 
	
	void change(int i,int value)//�޸ĵ�i��Ԫ��Ϊvalue 
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
	
	void erase_(int i)//ɾ����i��Ԫ�� 
	{
		heap[posi[i]]=-INF;
		up(posi[i]);
		pop();
	}
	
	//�븸�׽ڵ�Ƚϣ���С�ڸ��׽ڵ㣬�򽻻��� 
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
	//���С�Ķ��ӽڵ�Ƚϣ������ڣ��򽻻��� 
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
