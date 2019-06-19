#pragma warning(disable : 4996)
#include <stdio.h>
#define YES 1
#define NO 0

int main(void)
{
	long long int N; // длинное целое число
	int res = 0; // результат (самая левая единица в двоичной системе)
	int i;
	int j;
	int flag;
	printf ("N = ");
	scanf ("%lli", &N); // ввод длинного целого числа

	/*вывод в двоичном виде*/
	if (N >= 0)
	{
		for (j = 8; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				printf("%d", (N >> j * 4 - i & 1));
			}
			printf(" ");
		}
	}
	else
	{
		for (j = 8, flag = YES; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				if (flag == YES)
				{
					flag = NO;
					printf("1");
				}
				else
				{
					printf("%d", ((~N + 1) >> j * 4 - i & 1));
				}
			}
			printf(" ");
		}
	}
	printf("\n"); // конец вывода в двоичном виде

	while (N > 0) // пока N не станет равно 0
	{
		res = res + 1; // увеличиваем позицию результата
		N = N >> 1; // сдвигаем исходное число вправо (аналог деления на 2 без остатка)
	}
	printf("pos = %d", res);
	return 0;
}
