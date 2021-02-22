#include <stdio.h>
int main()
{
	int a = 10;
	printf("%10c salut\n", 'c');
	printf("%.2s salut\n", "dix");
	printf("%20p salut\n", &a);
	printf("%.10d salut\n", 10);
	printf("%.10i salut\n", 10);
	printf("%.10u salut\n", 10);
	printf("%.10x salut\n", 10);
	printf("%.010X salut\n", 10);
	printf("%% salut\n");
}
