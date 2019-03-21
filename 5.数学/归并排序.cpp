#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define MAXN
#define EPS 0.0000000001
#define INF 100000000

using namespace std;
int a[MAXN];
int b[MAXN];
int num[MAXN];

void merge(int num[],int first,int mid,int last,int *p)
{
	int i=first;
	int n=mid;
	int j=mid+1;
	int m=last;
	while(i<=n&&j<=m){
		if(a[i]<a[j]) p[k++]=a[i++];
		else p[k++]=a[j++];
	}
	while(i<=n) p[k++]=a[i++];
	while(j<=m) p[k++]=a[j++];
	
	for(int i=0;i<k;i++){
		a[first+k]=p[i];
	}
} 

void mergesort(int num[],int first,int last,int *p)
{
	if(first<last){
		int mid=(last+first)/2;
		mergesort(num,first,mid,p);
		mergesort(num,mid+1,last,p);
		merge(num,first,last,p);
	}
}

bool Mergesort(int num[],int n)
{
	int *p=new int[n];
	if(p==NULL) return false;
	mergesort(num,0,n-1,p);
	delete []p;
	return true;
}

int main()
{
	int n;

	
	return 0;
}
