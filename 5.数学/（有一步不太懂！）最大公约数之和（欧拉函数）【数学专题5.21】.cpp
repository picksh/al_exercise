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
#define MAXM 10007
#define pi 3.1415926

using namespace std;

int n;
ll ef(int n) 
{ 
    ll cnt = n; 
    int i; 
    for(i = 2; i * i <= n; i++){ 
        if(n % i == 0) 
        { 
            cnt -= cnt / i;      //   (x-x/p1) *(1-1/p2)*(1-1/p3)*(1-1/p4).....
            while(n % i == 0) 
                n /= i; 
        } 
    }
    if(n > 1) cnt -= cnt / n;
    return cnt; 
} 

int main(){
    while(~scanf("%d",&n)){
        ll ans = 0;
        for(int i = 1; i <= (int)sqrt(n); i++){
            if(n % i == 0){
                ans += ef(n / i) * i;
                if(n / i != i){
                    ans += ef(i) * (n / i);   //这个看不懂！！ 
                }
            }
        } 
        printf("%lld\n",ans);
    }
    return 0;
}
