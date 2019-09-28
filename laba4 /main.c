#include <stdio.h>

#define YES 1
#define NO 0
#define MAXLINE 1000

void process_line (char line[]); // объявдениие функции

int main(void)
{
	char line[MAXLINE]; // объявляем символьный мвссив
	printf ("Please, enter some words\nWARNING: even words will be deleted\n");
	gets(line); // ввод
	process_line(line);
	printf ("Result:\n");
	puts(line); // вывод
	return 0;
}

void process_line (char line[])
{
	char c; // текущий символ
	int word = NO; // признак слова
	int chetnoe = NO; // признак четности
	int symb = NO; // признак лишнего символа
	char prev_c = ' '; // предыдущий символ
	int start = 0; // позиция начала слова
	int i = 0; // позиция символа исходной строки
	int pos = 0; // позиция символа результирующей строки
	int cnt = 1; // счетчик слов

	do
	{
		c = line[i]; // берем текущий символ
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // если текущий символ разделитель,
		{
			if (word == YES && chetnoe == NO || symb == YES) // если проходит по 1/2 условию,
			{
				for (; start < i; start++, pos++) // копируем слово до разделителя
				{
					line[pos] = line[start]; // копирование
				}
			}

			if (symb == NO && word == YES) // если нет лишних символов и есть признак слова, то
			{
				cnt++; // увеличиваем счетчик
			}

			line[pos++] = c; // вставляем текущий разделитель

			symb = NO;
			word = NO;
		}
		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}

			if (word == NO) // если слова ещё нет,
			{
				start = i; // запоминаем первую букву
			}

			if (cnt % 2 == 0) // если слово четное,
			{
				chetnoe = YES; // запоминаем
			}
			else // если нет,
			{
				chetnoe = NO;
			}
			word = YES;
		}
		i++;
	} while (c != '\0'); // продолжаем до конца строки
}
