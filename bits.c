#include <stdio.h>

#define MAXBITS 31
#define NTHBIT(x, n) ((x) & (1 << n))

int nrbits(int a, int b, int n)
{
	if (n == 0)
		return 0;
	
	if (NTHBIT(a, n) == 0 && NTHBIT(b, n) == 0)
		return nrbits(a, b, n - 1);
	
	if (NTHBIT(a, n) == 0 && 0 != NTHBIT(b, n))
	{
		int y = (1 << n);
		int x = y - 1;
		return nrbits(a, x, n) + nrbits(b, y, n);
	}

	if (NTHBIT(a, n) != 0 && 0 != NTHBIT(b, n))
		return (b - a + 1) + nrbits(a, b, n - 1);
}

int main()
{
	int a = 1;
	int b = 3;
	int ret = nrbits(a, b, MAXBITS);
	printf("nr 1's = %d\n", ret);
    return 0;
}