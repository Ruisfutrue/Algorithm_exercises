
#include <cstdio>
#include <algorithm>

using namespace std;

int data[100005];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		int isWin = 1;
		int maxNum = 0;
		int maxSeat = 0;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &data[i]);
		}
		for (int i = 1; i < n; ++i)
		{
			if (data[i] <= 0)
			{
				int ok = 0;
				for (int j = i; j > 0; --j)
				{
					if (data[j] > (i - j))
					{
						ok = 1;
						break;
					}
				}
				if (0 == ok)
				{
					isWin = 0;
					break;
				}
			}
		}
		if (1 == isWin)
		{
			printf("I Win!\n");
		}
		else
		{
			printf("Too Far!\n");
		}
	}
	return 0;
}
