/* 
 Author: 李瑞
 Result: AC	Submission_id: 313074
 Created at: Mon Oct 09 2017 15:09:20 GMT+0800 (CST)
 Problem_id: 858	Time: 203	Memory: 1444
*/

#include<cstdio>
#include<cstring>

#define ll long long

ll ways[55][55];

int main(int argc, char const *argv[])
{
	int n;
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		memset(ways, 0, sizeof(ways));
		ways[a][a] = 1;
		ways[a][a + 1] = 1;

		for (int j = a + 1; j <= b; ++j)
		{
			if (ways[a][j] == 0)
			{
				ways[a][j] = ways[a][j - 1] + ways[a][j - 2];
			}
		}
		printf("%lld\n", ways[a][b]);
	}
	return 0;
}
