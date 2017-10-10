
#include<cstdio>
#include<cstring> // "memset" function was included in <cstring> header.

#define ll long long

ll ways[55][55];

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		memset(ways, 0, sizeof(ways));
		ways[a][a] = 1;
		ways[a][a + 1] = 1;

		for (int j = a + 1; j <= b; ++j)
		{
			if (0 == ways[a][j])
			{
				ways[a][j] = ways[a][j - 1] + ways[a][j - 2];
			}
		}
		printf("%lld\n", ways[a][b]);
	}
	return 0;
}
