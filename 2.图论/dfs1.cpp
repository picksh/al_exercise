/*A Knight's Journey
poj-2488*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define MAXN 30

using namespace std;
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
vector<pair<int,int> > route; 
int firstf=0;
bool v[MAXN][MAXN];

int p,q;

bool dfs(int x,int y)
{
	if(x<1||x>p||y<1||y>q) return false;
	if(v[x][y]) return false;
	//else v[x][y]=true;
	if(x==1&&y==1){
		if(!firstf) {
			firstf=1;
			v[1][1]=true;
		}
		
		else return true;
	} 
	bool flag=false;
	v[x][y]=true;
	for(int i=0;i<8;i++){
		if(dfs(x+dir[i][1],y+dir[i][0])) {
			flag=true;
			break;
		}
	}
	if(flag)
	{
		route.push_back(make_pair(x,y));
	//	v[x][y]=true;
	}else return false;
}

int main()
{
	int n;
	int tot=0;
	scanf("%d",&n);
	while(n--){
		route.clear();
		memset(v,0,sizeof(v));
		firstf=0;
		tot++;
		scanf("%d%d",&p,&q);
    	printf("Scenario #%d:",tot);
    	if(dfs(1,1)) printf("impossible\n");
    	else{
    		if(p==1&&q==1) printf("A1\n");
    		else{
    			for(int i=route.size()-1;i>=0;i--){
    			char k=char(route[i].second-1+'A');
    			printf("%c%d\n",k,route[i].first);
    		//	printf("%d",route[i].first);
    			
			}
			}
		}
	printf("\n");	
	}
	
	return 0;
}
