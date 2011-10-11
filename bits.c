#include <stdio.h>

#define MAXBITS 31
#define GETNTHBIT(x, n) ((x) & (1 << n))
#define CLEARNTHBIT(x, n) ((x) &= ~(1 << n))

int nrbits(int a, int b, int n)
{
	if (n == 0)
		return b;
	
	if (GETNTHBIT(a, n) == 0 && GETNTHBIT(b, n) == 0)
		return nrbits(a, b, n - 1);
	
	if (GETNTHBIT(a, n) == 0 && 0 != GETNTHBIT(b, n))
	{
		int y = (1 << n);
		int x = y - 1;
		return nrbits(a, x, n) + nrbits(b, y, n);
	}

	if (GETNTHBIT(a, n) != 0 && 0 != GETNTHBIT(b, n))
	{
		CLEARNTHBIT(a, n);
		CLEARNTHBIT(b, n);
		return (b - a + 1) + nrbits(a, b, n - 1);
	}
}

int main()
{
	int a = 1;
	int b = 3;
	int ret = nrbits(a, b, MAXBITS);
	printf("nr 1's = %d\n", ret);
    return 0;
}