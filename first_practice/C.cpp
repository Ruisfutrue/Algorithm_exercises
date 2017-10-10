
#include <cstdio>

using namespace std;

struct Matrix {
	Matrix(int a1 = 0, int b1 = 0, int c1 = 0, int d1 = 0)
	{
		a = a1;
		b = b1;
		c = c1;
		d = d1;
	}
	int a, b, c, d;
};

Matrix base(1, 1, 1, 0);

//计算两个矩阵的乘积
Matrix cal_matrix(Matrix m1, Matrix m2)
{

	Matrix temp;
	temp.a = (m1.a * m2.a + m1.b * m2.c) % 10007;
	temp.b = (m1.a * m2.b + m1.b * m2.d) % 10007;
	temp.c = (m1.c * m2.a + m1.d * m2.c) % 10007;
	temp.d = (m1.c * m2.b + m1.d * m2.d) % 10007;
	return temp;
}

//计算base矩阵的n次方
Matrix cal_fab(int n, Matrix base)
{
	if (n == 1)
	{
		return base;
	}
	else
	{
		Matrix hello(1, 0, 0, 1);

//		快速幂
		while (n > 1)
		{
			if (1 == n % 2)
			{
				hello = cal_matrix(base, hello);
			}
			base = cal_matrix(base, base);
			n /= 2;
		}
		return cal_matrix(base, hello);
	}
}

int main()
{
	int n;
	while(1 == scanf("%d", &n))
	{
		if (0 == n)
		{
			printf("0\n");
		}
		else if (1 == n)
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n", cal_fab(n - 1, base).a);
		}
	}
	return 0;
}
