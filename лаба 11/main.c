#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define YES 1
#define NO 0

int main(void)
{
	char def[7] = "define"; // массив для define

	HANDLE hStdout;
	WORD foregroundColor0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_BLUE;

	FILE* fpin = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "rt"); // открыть файл для чтения;
	if (fpin == NULL)
	{
		return;
	}

	char line[100]; // текущая строка
	char* ptr = NULL;
	char* pptr;
	char mas[100][100]; //хранит все макроимена
	int j = 0;
	int k = 0;

	while (!feof(fpin)) //цикл до конца файла
	{
		fgets(line, 100, fpin); //считываем новую строку
		ptr = line; //указатель на начало строки

		while (*ptr != '\n' && *ptr != '\0') //пока строка не закончилась
		{
			int i = 0;
			if (*ptr == '#') //если нашли решетку
			{
				pptr = ptr + 1; //указатель на след элемент
				int flag = NO; //если no, то текущее слово -- define

				do
				{
					if (*pptr != def[i])  //если текущий символ не равен текущему элементу массива def, то
					{
						flag = YES; //поднимаем флаг, текущее слово не define
						break;
					}
					pptr++; //увеличиваем, смотрим след символ
					i++; // увеличиваем, смотрим след символ
				} while (*pptr != ' ' && def[i] != '\0'); // пока текущий символ не равен пробелу или  массив def не закончился

				if (flag == NO && (*pptr == ' ' || *pptr == '\0' || *pptr == '\n') && def[i] == '\0') //если оба массива закончились и равны
				{
					while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0') // цикл до конца слова
					{
						ptr++; //был на #, увеличиваем, пока не станет равен пробелу, \n, \0
					}

					pptr = ptr; 
					j = 0;
					pptr++; //смотрим след эл
					while (*pptr != ' ' && *pptr != '\n' && *pptr != '\0') // цикл до конца слова
					{
						mas[k][j++] = *pptr++; //сохраняем в массив макроимя
					}
					mas[k][j++] = '\0'; //вставляем \0
					k++; //смотрим след строчку
				}
				flag = NO; //если no, то текущее слово -- define
			}

			while (*++ptr != ' ' && *ptr != '\n' && *ptr != '\0') //увеличиваем, пока не станет равен пробелу, \n, \0
			{
			}
		}
	}
	fclose(fpin); // закрыть входной файл

	fpin = fopen("C:\\Users\\HP\\source\\repos\\file.txt", "rt"); // открыть файл для чтения;
	while (!feof(fpin))
	{
		fgets(line, 100, fpin); //считываем новую строку
		ptr = line; //указатель на начало строки
		char massiv[100];
		int n;

		while (*ptr != '\n' && *ptr != '\0') //пока строка не закончилась
		{
			pptr = ptr;
			n = 0;
			while (*pptr != ' ' && *pptr != '\n' && *pptr != '\0') //цикл до конца слова
			{
				massiv[n++] = *pptr++; //записываем в массив
			}
			massiv[n++] = '\0'; //вставляем \0

			for (int p = 0; p < k; p++) 
			{
				if (strcmp(massiv, mas[p]) == 0) //если равны, то выделяем цветом
				{
					SetConsoleTextAttribute(hStdout, foregroundColor0);
				}
			}

			while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0') //цикл до конца слова
			{
				printf("%c", *ptr++); // выводим 
			}

			SetConsoleTextAttribute(hStdout, 7); // белые символы, черный фон

			if (*ptr != '\0')
			{
				printf("%c", *ptr++);
			}
		}
		if (*ptr == '\n')
		{
			printf("%c", *ptr++);
		}
	}
	return 0;
}
