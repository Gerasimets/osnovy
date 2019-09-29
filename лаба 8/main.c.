#include <stdio.h>

#define YES 1
#define NO 0
#define MAXLINE 1024

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
	int cnt = 1; // счетчик слов
char *in_ptr = line; // указатель на текущий символ
                 // входной строки
	char *out_ptr = line; // указатель на текущий символ
	               // выходной строки
	char *word_ptr = line; // указатель на начало слова

	do
	{
		c = *in_ptr; // берем текущий символ
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // если текущий символ разделитель,
		{
			if (word == YES && chetnoe == NO || symb == YES) // если проходит по 1/2 условию,
			{
				for (; word_ptr < in_ptr; word_ptr++, out_ptr++) // копируем слово до разделителя
				{
					*out_ptr = *word_ptr; // копирование
				}
			}

			if (symb == NO && word == YES) // если нет лишних символов и есть признак слова, то
			{
				cnt++; // увеличиваем счетчик
			}

			*out_ptr++ = c; // вставляем текущий разделитель

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
				word_ptr = in_ptr; // запоминаем адрес первой буквы
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
		in_ptr++;
	} while (c != '\0'); // продолжаем до конца строки
}
