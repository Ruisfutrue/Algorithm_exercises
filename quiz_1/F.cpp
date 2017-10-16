
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const int maxN = 100 + 5;

struct Stick {
    int x;
    int h;
} sticks[maxN];

bool cmp(Stick s1, Stick s2) {
    return s1.x < s2.x;
}

int main() {
    int n = 0;
    while (EOF != scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &sticks[i].x, &sticks[i].h);

        sort(sticks, sticks + n, cmp);
        double maxStorage = 0.0;

        for (int j = 0; sticks[j].x <= 0 && j < n; ++j) {
            for (int i = n - 1; sticks[i].x >= 0 && i > -1; --i) {
                double temp = PI * (sticks[i].x - sticks[j].x) * 
                (sticks[i].x - sticks[j].x) * min(sticks[i].h, sticks[j].h) / 4;
                maxStorage = max(maxStorage, temp);
            }
        }
        printf("%.3lf\n", maxStorage);
    }
    return 0;
}
