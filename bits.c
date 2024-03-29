#include <stdio.h>

#define MAXBITS 31
#define GETNTHBIT(x, n) ((x) & (1 << n))
#define CLEARNTHBIT(x, n) ((x) &= ~(1 << n))
#define ISFULL(x) (((x) & ((x) + 1)) == 0)


unsigned long long nrbits(int a, int b, int n)
{
	if (n == 0)
		return b;
	
	if (GETNTHBIT(a, n) == 0 && 0 == GETNTHBIT(b, n))
		return nrbits(a, b, n - 1);
	
	if (GETNTHBIT(a, n) == 0 && 0 != GETNTHBIT(b, n))
	{
		if (ISFULL(b) && a == 0)
			return (1LL << n) * (n + 1);
		int y = (1 << n);
		int x = y - 1;
		return nrbits(a, x, n) + nrbits(y, b, n);
	}

	if (GETNTHBIT(a, n) != 0 && 0 != GETNTHBIT(b, n))
	{
		CLEARNTHBIT(a, n);
		CLEARNTHBIT(b, n);
		return (1LL + b - a) + nrbits(a, b, n - 1);
	}
}

unsigned long long get_nr_set(int a, int b)
{
	if (a < 0 && b >= 0)
		return nrbits(a, -1, MAXBITS) + nrbits(0, b, MAXBITS);
	else
		return nrbits(a, b, MAXBITS);
}

int main()
{
	int nr_test = 0;
	scanf("%d", &nr_test);

	int a, b, i;
	unsigned long long ret;
	for (i = 0; i < nr_test; i++) {
		scanf("%d %d", &a, &b);
		ret = get_nr_set(a, b);
		printf("%llu\n", ret);
	}
    return 0;
}