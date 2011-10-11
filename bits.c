#include <stdio.h>

#define MAXBITS 32

int nrbits(char *a, char *b, int n)
{
	if (a[n] == 0 && 0 == b[n])
		return nrbits(a, b, n - 1);
	
	if (a[n] == 0 && 1 == b[n])
	{
		int y = (1 << n);
		int x = y - 1;
		return nrbits(a, (char*)&x, n) + nrbits(b, (char*)&y, n);
	}

	if (a[n] == 1 && 1 == b[n])
		return ((int)b - (int)a + 1) + nrbits(a, b, n - 1);
}

int main()
{
	int a = 1;
	int b = 3;
	int ret = nrbits((char*)&a, (char*)&b, MAXBITS);
	printf("nr 1's = %d\n", ret);
    return 0;
}