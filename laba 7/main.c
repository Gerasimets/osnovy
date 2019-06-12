#include<stdio.h> 
#define YES 1
#define NO 0

int main(void)
{
	long int N;
	long i;
	int	j;
	int k;
	scanf_s("%d", &N);
	
		for (j = 8; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				printf("%d", (N >> j * 4 - i & 1));
			}
			printf(" ");
		}
	for (i = 0; N > 0;i ++)
	{
		N = N >> 1;
	}
	printf("%d\n", i);
	system("pause");
	return 0;
}
