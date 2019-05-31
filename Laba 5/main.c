#include<stdio.h>
#include<conio.h>
#define N 10
int main()
{
int m[N];
int i, max;
for (i = 0; i < N; i++)
scanf_s("%d", &m[i]);
max = m[0];
for (i = 0; i < N; i++)
{
if (m[i] > max)
max = m[i];
}
for (i = 0; i < N; i++)
{
if (m[i] < 0)
m[i] = m[i] / max;
}
for (i = 0; i < N; i++)
printf("%d ", m[i]);
printf("\n");
getch();
return 0;
}
