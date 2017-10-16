
#include <cstdio>

#define ll long long

int main() {
    ll a;
    // num[a % b] = (a + 1) / 2 + 1
    while (scanf("%lld", &a) == 1)
        printf("%lld\n", (a + 1) / 2 + 1);
    return 0;
}
