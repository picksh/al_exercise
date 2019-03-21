/*
1.分治
2.实现排序 
3.排序过程中记录逆序对数

 空间复杂度 n 
 时间复杂度 o(nlogn) 
 
 notice:输出可能会超 int !!-> n^2 
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
int n;
int num[MAXN];
int temp[MAXN];
int ans=0;


void merge_(int l,int m,int r)
{
	int i=l;
	int k=l;
	int j=m+1;
	while(i<=m&&j<=r){
		if(num[i]>num[j]){
			ans+=m-i+1; 
			temp[k++]=num[j++];
		}
		else{
			temp[k++]=num[i++];
		}
	}
	while(i<=m) temp[k++]=num[i++];
	while(j<=r) temp[k++]=num[j++];
	for(int i=l;i<=r;i++){
		num[i]=temp[i];
	}
}

void merge_sort(int l,int r)
{
	if(l<r){
		int m=(l+r)>>1;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge_(l,m,r);
	}
 } 

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	merge_sort(0,n-1);
	printf("%d\n",ans);
 } 
