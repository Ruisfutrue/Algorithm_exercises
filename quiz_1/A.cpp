
#include <cstdio>
using namespace std;

// calculate n!
double factorial(double n) {
    double ans = 1.0;
    for (int i = 1; i <= n; ++i)
        ans *= i;
    return ans;
}

int main() {
    int n;
    double D[25];
    // initialization
    D[0] = 0;
    D[1] = 0;
    D[2] = 1;
    
    for (int i = 3; i < 25; ++i)
        D[i] = (i - 1) * (D[i - 2] + D[i - 1]); // 递推公式
    while (1 == scanf("%d", &n))
        printf("%.2lf%%\n", D[n] / factorial(n) * 100);
    return 0;
}
// test Git push 
