/*
    题意：k ^ n = p，求k
    1. double + pow：因为double装得下p，k = pow (p, 1 / n);
    基础知识: 类型    长度 (bit)    有效数字    绝对值范围
            float    32             6~7         10^(-37) ~ 10^38
            double    64            15~16        10^(-307) ~ 10^308
       long double    128              18~19         10^(-4931) ~ 10 ^ 4932
    2. 二分查找：和1类似
    3. 取对数：n*ln(k)=ln(p)    ln(k)=ln(p)/n    k=exp(ln(p)/n)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int main(void)        //POJ 2109 Power of Cryptography
{
    //freopen ("D.in", "r", stdin);
    double n, p, k;

    while (~scanf ("%lf%lf", &n, &p))
    {
        printf ("%.0f\n", pow (p, 1 / n));
    }

    return 0;
}

/*
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

void BinarySearch(int l, int r, double n, double p)
{
    int mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        double tmp = pow (mid, n);
        if (tmp == p)
        {
            printf ("%d\n", mid);    return ;
        }
        else if (tmp < p)    l = mid + 1;
        else    r = mid - 1;
    } 
}

int main(void)
{
    //freopen ("D.in", "r", stdin);

    double n, p;

    while (~scanf ("%lf%lf", &n, &p))
    {
        BinarySearch (1, 1e9, n, p);
    }

    return 0;
}
*/

/*
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)        //POJ 2109 Power of Cryptography
{
    //freopen ("D.in", "r", stdin);

    double n, p;

    while (~scanf ("%lf%lf", &n, &p))
    {
        printf ("%.0f\n", exp (log (p) / n));
    }

    return 0;
}
*/
