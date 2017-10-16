
#include <cstdio>

#define ll long long
const int maxN = 50 + 2;

struct Way {
    ll total; // total ways
    ll safe; // step 1 or 2
    ll once; // step 3
    Way(int a = 0, int b = 0, int c = 0) {
        total = a;
        safe = b;
        once = c;
    }
} ways[maxN];

void init(Way * arr) {
    arr[1] = Way(1, 1, 0);
    arr[2] = Way(1, 1, 0);
    arr[3] = Way(2, 2, 0);
}

void cal_ways(Way * arr) {
    init(arr);
    for (int i = 4; i < maxN ; ++i) {
        arr[i].safe = arr[i - 1].total + arr[i - 2].total;
        arr[i].once = arr[i - 3].safe;
        arr[i].total = arr[i].safe + arr[i].once;
    }
}

int main () {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        cal_ways(ways);
        printf("%lld\n", ways[n + 1].total);
    }
    return 0;
}

