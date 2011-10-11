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
		return nrbits(a, x, n) + nrbits(y, b, n);
	}

	if (GETNTHBIT(a, n) != 0 && 0 != GETNTHBIT(b, n))
	{
		CLEARNTHBIT(a, n);
		CLEARNTHBIT(b, n);
		return (b - a + 1) + nrbits(a, b, n - 1);
	}
}

int get_nr_set(int a, int b)
{
	if (a < 0 && b >= 0)
		return nrbits(a, -1, MAXBITS) + nrbits(0, b, MAXBITS);
	else
		return nrbits(a, b, MAXBITS);
}

int main()
{
	int a = -3;
	int b = 0;

	int ret = get_nr_set(a, b);

	printf("nr 1's = %d\n", ret);
    return 0;
}