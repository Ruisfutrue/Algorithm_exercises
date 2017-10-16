
#include <iostream>
#include<string>
using namespace std;

#define ll long long

int main() {
    int n;
    int h1, h2;
    string x1, x2;
    cin >> n;
    while (n--) {
        ll ans1 = 0, ans2 = 0;
        cin >> h1 >> x1 >> h2 >> x2;
        for (int i = 0; i < x1.length(); ++i)
            ans1 = (x1[i] - '0') + h1 * ans1;

        for (int i = 0; i < x2.length(); ++i)
            ans2 = (x2[i] - '0') + h2 * ans2;
        cout << ans1 + ans2 << endl;
    }
    return 0;
}
