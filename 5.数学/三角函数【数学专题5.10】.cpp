#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 200000+7;

LL n;
int a[6] = {1,-1,-2,-1,1,2};
int main(){
    scanf("%lld",&n);
    printf("%d",a[(n+5)%6]);
    return 0;
}

