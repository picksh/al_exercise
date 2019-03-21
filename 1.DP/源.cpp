#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;
#define MAX_NUM 1310
typedef unsigned long long ull;
ull matrix[MAX_NUM][MAX_NUM];
ull dp[MAX_NUM][MAX_NUM];
int main()
{
		freopen("a.txt","r",stdin);
	int t;
	ull m, n, x, y;
	ull input;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(matrix, 0, sizeof(matrix));
		memset(dp, 0, sizeof(dp));
		scanf("%lld %lld %lld %lld", &m, &n, &x, &y);

		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				scanf("%lld", &matrix[a][b]);
				if (b < y)
					dp[a][0] += matrix[a][b];
				if (b <= n - y + 1 && b >= y)
				{
					dp[a][b - y + 1] = dp[a][b - y] - matrix[a][b - y] + matrix[a][b];
				}
			}
		}
		for(int i=0;i<m-x;i++){
			for(int j=0;j<n-y;j++){
			cout<<dp[i][j]<<" "; 
		}
	}

		ull max = 0;
		for (int b = 0; b <= n - y; b++)
		{
			ull tmp = 0;
			for (int j = 0; j < x; j++)
			{
				tmp += dp[j][b];
			}
			max = tmp > max ? tmp : max;

			for (int a = 1; a <= m - x; a++)
			{
				tmp = tmp - dp[a - 1][b] + dp[a + x - 1][b];
				max = tmp > max ? tmp : max;
			}
		}
		cout << max << endl;

	}

}
