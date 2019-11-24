#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#pragma warning (disable : 4996)

typedef struct
{
	char k[32];
	int i;
	int v;
	int n;
	int p;
	int o;
	int np;
}liga;

int menu(void);
void tab(void);
void igra(void);
void nev(void);
void poisk(void);
int findID(FILE * f, int id, liga *li);

int main()
{
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int a;
	while ((a = menu()) != 5)
	{
		switch (a)
		{
		case 1:
			tab();
			break;
		case 2:
			igra();
			break;
		case 3:
			nev();
			break;
		case 4:
			poisk();
			break;
		};
	}
	return 0;
}

int menu()
{
	int m;
	system("cls");  //очисткаэкрану
	printf("\t\t***Выберитепунктменю:***\n");
	printf("\t1-Вывод турнирной таблицы\n");
	printf("\t2-Внесение изменения о проведенном матче\n");
	printf("\t3-Создание турнирной таблицы нового турнира\n");
	printf("\t4-Поиск команды\n");
	printf("\t5-Выход из программы\n");
	scanf_s("%d", &m);
	return m;
}

void tab(void)
{
	system("cls");
	int    n = 0;
	liga li = { 0 };//Обнулили поля структуры
	FILE *f = NULL;
	if (!(f = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "rb")))
		printf("Файл table.dat нe открыт\n");
	else
	{
		//Узнаём число структур в файле
		fseek(f, 0, SEEK_END);
		if (!(n = ftell(f) / sizeof(liga)))
			printf("Файл table.dat не содержит достаточно информации даже для 1-ой структуры\n");
		else
		{
			fseek(f, 0, SEEK_SET);
			printf("%52s", "------------------------------------------\n");
			printf("%31s%4s%4s%4s%4s%4s\n", "Команда", "I", "В", "Н", "П", "О");
			printf("%52s", "------------------------------------------\n");
			while (!feof(f))
			{
				if (fread((void *)&li, 1, sizeof(liga), f))
					printf("%31s%4d%4d%4d%4d%4d\n", li.k, li.i, li.v, li.n, li.p, li.o);
			}
		}
		fclose(f);
	}
	system("pause");
}

void igra(void)
{
	system("cls");
	int  n = 0;
	int id1, id2, result;
	int idpos1, idpos2;//Позиции в файле структур 1-й и 2-й команд
	liga li1 = { 0 };//Обнулили поля структуры 1-й команды 
	liga li2 = { 0 };//Обнулили поля структуры 2-й команды 
	FILE *f = NULL;
	if (!(f = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "rb+")))
		printf("Файл table.dat неоткрыт\n");
	else
	{
		//Узнаём число структур в файле
		fseek(f, 0, SEEK_END);
		if (!(n = ftell(f) / sizeof(liga)))
			printf("Файл table.dat не содержит достаточно информации даже для 1-ой структуры\n");
		else
		{
			printf("Введите id первой команды : ");
			scanf_s("%d", &id1);
			printf("Введите id второй команды : ");
			scanf_s("%d", &id2);
			if (!findID(f, id1, &li1))
				printf("Файл не содержит команды из ID %d\n", id1);
			else
			{
				idpos1 = ftell(f);
				if (!findID(f, id2, &li2))
					printf("Файл не содержит команды из ID %d\n", id2);
				else
				{
					idpos2 = ftell(f);
					//В любом случае команды сыграли поэтому
					//у каждой +1 игра
					li1.i = li1.i + 1;
					li2.i = li2.i + 1;
					printf("Введите результат игры:\n");
					printf("1 - Первая команда победила\n");
					printf("2 - Вторая команда победила\n");
					printf("Другая цифра - ничья\n");
					scanf_s("%d", &result);
					switch (result)
					{
					case 1:
						li1.v = li1.v + 1;
						li1.o = li1.o + 3;
						li2.p = li1.p + 1;
						break;
					case 2:
						li2.v = li2.v + 1;
						li2.o = li2.o + 3;
						li1.p = li1.p + 1;
						break;
					default:
						li1.n = li2.n + 1;
						li2.n = li2.n + 1;
						li1.o = li1.o + 1;
						li2.o = li2.o + 1;
						break;
					};
					if (fseek(f, idpos1 - sizeof(liga), SEEK_SET))
						printf("Ошибка позиционирования в table.dat\n");
					else
						if (!fwrite((void *)&li1, 1, sizeof(liga), f))
							printf("ошибка записи в table.dat\n");

					if (fseek(f, idpos2 - sizeof(liga), SEEK_SET))
						printf("Ошибка позиционирования в table.dat\n");
					else
						if (!fwrite((void *)&li2, 1, sizeof(liga), f))
							printf("ошибка записи в table.dat\n");
				}
			}
		}
		fclose(f);
	}
	system("pause");
}

void nev(void)
{
	system("cls");
	int    n = 0;
	liga li = { 0 };//Обнулилиполяструктуры
	FILE *f = NULL;
	if (!(f = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "wb")))
		printf("Файл table.dat неоткрыт\n");
	else
	{
		while (n < 1)
		{
			printf("Введите количество команд : ");
			scanf_s("%d", &n);
			getchar();//убрали \n оставшийся от ввода
		}
		for (li.np = 1; li.np <= n; li.np = li.np + 1)
		{
			li.i = 0;
			li.v = 0;
			li.n = 0;
			li.p = 0;
			li.o = 0;
			printf("Название команды : ");
			scanf/*_s*/("%[^\n]", li.k);//Название может быть с пробелом
			getchar();//убрали \n оставшийся от ввода
			if (!fwrite((void *)&li, 1, sizeof(liga), f))
				printf("ошибка записи в table.dat\n");
		}
		fclose(f);
	}
	system("pause");
}

int findID(FILE * f, int id, liga *li)
{
	int flag = 0;//Флаг который сигнализирует была ли найдена нужная команда
	fseek(f, 0, SEEK_SET);
	while (!feof(f))
	{
		if (fread((void *)li, 1, sizeof(liga), f))
		{
			if (li->np == id)
				flag = 1;
		}
		if (flag == 1)
			break;
	}
	return flag;
}

void poisk(void)
{
	system("cls");
	int id, n = 0;
	liga li = { 0 };//Обнулили поля структуры
	FILE *f = NULL;
	if (!(f = fopen("table.dat", "rb")))
		printf("Файл table.dat неоткрыт\n");
	else
	{
		//Узнаём число структур в файле
		fseek(f, 0, SEEK_END);
		if (!(n = ftell(f) / sizeof(liga)))
			printf("Файл table.dat не содержит достаточно информации даже для 1-ой структуры\n");
		else
		{
			printf("Введите id команды : ");
			scanf_s("%d", &id);

			if (!findID(f, id, &li))
				printf("Файл не содержит команды из ID %d\n", id);
			else
			{
				printf("%52s", "------------------------------------------\n");
				printf("%31s%4s%4s%4s%4s%4s\n", "Команда", "I", "В", "Н", "П", "О");
				printf("%52s", "------------------------------------------\n");
				printf("%31s%4d%4d%4d%4d%4d\n", li.k, li.i, li.v, li.n, li.p, li.o);
			}
		}
		fclose(f);
	}
	system("pause");
}
