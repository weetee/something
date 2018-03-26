#include <stdio.h>

void PrintNumber(int n)
{
	if (n < 0)
	{
		printf("-");
		PrintNumber(-n);
	}
	else if (n < 10)
	{
		printf("%d", n);
	}
	else
	{
		PrintNumber(n/10);
		PrintNumber(n%10);
	}
}

int main()
{
	int num = 0;
	printf("Input a number: ");
	scanf("%d", &num);
	PrintNumber(num);
	printf("\n");
	return 0;
}
