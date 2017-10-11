#include <stdio.h>
void get(int *a, unsigned int *k)
{
	*k = 1;
	*k = *k <<= *a;
	*k = *k >>= 1;
}

int main()
{
	int a = 0;
	unsigned int k;
	printf("insert: ");
	scanf("%d", &a);

	int *f = &a; int *e = &k;
	get(f, e);

	printf("its: %d", k);
	
	printf("\nlooks like: %d", a);
	scanf("%d", &a);
	return 0;
}