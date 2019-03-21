/*HDU - 2544 */

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

using namespace std;


vector<int> father;
vecter<int> rank;

struct{
	
	void disjointset(int n):father(n),rank(n)
   {
	for(int i=0;i<n;i++){
		father[i]=i;
	    }
    }

    int findad(int i)
    {
	return father[i]=father[i]==i?i:findad(father[i]);
    }



    void merge(int x,int y)
    {
	int x1=findad(x);
	int y1=findad(y);
	if(rank[y1]>rank[x1]){
		father[x1]=y1;
		rank[y1]++;
	}else{
		father[y1]=x1;
		if(rank[x1]==rank[y1]){
			rank[x1]++;
		    }
	}
    }
	
};



int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		init(n,m);
		dij(n); 
		printf("%d\n",dis[n-1]);
	}
	return 0;
}
