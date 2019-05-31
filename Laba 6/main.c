#include <stdio.h>
#define K 4
#define N 4

int main(void)
{
​int MAS[K][N]; // массив из K на N элементов
​int copy[K][N]; // массив из К на N элементов
​int max=0; // максимальная сумма строки
​int min=91;//минимальная сумма строки
​int str; //номер строки
​int stlb; // номер столбца
​int m;// строка с максимальной суммой
​int s;//строка с минимальной суммой
​int summa; // сумма строки
​srand(time(NULL));​
​/*вводим каждый элемент массива*/
​for (str = 0; str < N; str++)
​{
​​for (stlb = 0; stlb < K; stlb++)
​​{
​​​MAS[str][stlb] = 0 + rand() % 10;
​​}
​}
​for (str = 0; str < N; str++)
​{
​​for (stlb = 0, summa = 0; stlb < K; stlb++)
​​{
​​​copy[str][stlb] = MAS[str][stlb];
​​}
​}
​/*вывод исходного массива для подсказки*/
​printf("original mass\n");
​for (str = 0; str < N; str++)
​{
​​for (stlb = 0; stlb < K; stlb++)
​​{
​​​printf("%4d ", MAS[str][stlb]);
​​}
​​printf("\n");
​}
​printf("\n");
​/*находим сумму строк*/
​for (str = 0; str < N; str++)
​{
​​for (stlb = 0, summa = 0; stlb < K; stlb++)
​​{
​​​summa = summa + MAS[str][stlb];
​​}
​​if (summa > max)
​​{
​​​m = str;
​​​max = summa;
​​}
​​if(summa < min)
​​{
​​​s = str;
​​​min = summa;
​​}
​}
​for (stlb = 0; stlb < N; stlb++)
​{
​​MAS[m][stlb] = copy[s][stlb];
​​MAS[s][stlb] = copy[m][stlb];
​}
​/*вывод результирующего массива*/
​printf("processed mass\n");
​for (str = 0; str < N; str++)
​{
​​for (stlb = 0; stlb < K; stlb++)
​​{
​​​printf("%4d ", MAS[str][stlb]);
​​}
​​printf("\n");
​}
​return 0;
}
