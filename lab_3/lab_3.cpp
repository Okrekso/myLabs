#include <stdio.h>

int find(char a, char *str)
{
	int pop = 0;
	char k = str[0]; int i = 0;
	while (k != '\0')
	{
		i++;
		k = str[i];
		pop += k == a ? 1 : 0;
	}
	return pop;
}
char get(char *str)
{
	char srch = str[0]; int i = 0;
	char pop = str[0]; int popCount = 1;
	while (srch != '\0')
	{
		i++;
		srch = str[i];
		pop = find(srch, str)>popCount ? srch : pop;
		popCount = find(srch, str)>popCount ? find(srch, str) : popCount;
	}
	return pop;
}
int main()
{
	char str[100];
	scanf("%s", str);
	printf("\nit's: %c", get(str));
	return 0;
}