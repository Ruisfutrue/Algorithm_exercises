#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
const int maxN = 10000 + 10;

ll a[maxN], b[maxN], tmp[maxN];

ll merge(int start, int mid, int end) {
	ll cnt = 0;
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid) {
		while (j <= end && b[i] > 2 * b[j])
			++j;
		cnt += (j - mid - 1);
		++i;
	}
  
	i = start;
	j = mid + 1;
	while (i <= mid && j <= end) {
		if (b[i] > b[j])
			tmp[k++] = b[j++];
		else
			tmp[k++] = b[i++];
	}
	while (i <= mid)
		tmp[k++] = b[i++];
	while (j <= end)
		tmp[k++] = b[j++];
    
	for (int i = 0; i < k; ++i)
		b[start + i] = tmp[i];
	return cnt;
}

ll lilo(int start, int end) {
	ll cnt = 0;
	if (start < end) {
		int mid = (start + end) / 2;
		cnt += (lilo(start, mid) + 
			lilo(mid + 1, end) + merge(start, mid, end));
	}
	return cnt;
}

int main() {
	int n, t, p, q;
	while (1 == scanf("%d", &n)) {
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		scanf("%d", &t);
		for (int i = 0; i < t; ++i) {
			scanf("%d %d", &p, &q);
			if (p >= q)
				swap(p, q);
			for (int j = p; j <= q; ++j)
				b[j] = a[j];
			printf("%lld\n", lilo(p, q));
		}
	}
	return 0;
}

