
#include <cstdio>

using namespace std;

int data[1000005];

int Qsort(int a[],int x,int y) {
    if(x >= y) return 0;
    int i = x;
    int j = y;
    int temp;
    int key;
    if (0 == (y - x + 1) % 2)
        key = a[(i + j) / 2 + 1];
    else
        key = a[(i + j) / 2];
        
    while(i < j) {
        while(a[i] < key) ++i;
        while(a[j] > key) --j;
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
            --j;
        }
    }
    return j;
}

int main() {
    int n;
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d",&data[i]);
        int temp1 = Qsort(data, 0, n - 1);
        int temp2 = Qsort(data, 0, temp1);

        for (int i = temp2 + 1; i <= temp1; ++i)
            printf("%d ", data[i]);
        printf("\n");
    }
    return 0;
}

