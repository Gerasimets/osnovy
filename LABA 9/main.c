#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>

# define YES 1
# define NO 0
# define MAXLINE 1024

int main(int argc, char *argv[])
{
	// указатели на структуру типа FILE для входной и выходного файлов
	FILE *fpin;
	FILE *fpout;

	char line[MAXLINE]; // текущая строка
	char result[MAXLINE]; // результирующая строка
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	int chetnoe = NO; // признак, что в слове четное кол-во букв
	int cnt = 0;// счетчик кол-ва букв в слове
	char *in_ptr = line; // указатель на текущий символ входной строки
	char *out_ptr = result; // указатель на текущий символ выходной строки
	char *word_ptr = line; // указатель на начало слова
	char *output_ptr = result; // указатель на результирующий масcив

	if (argc == 2)
	{
		argv[2] = "C:\\Users\\HP\\source\\repos\\Project9\\Project9\\result.txt";
	}
	else if (argc == 1)
	{
		argv[1] = "C:\\Users\\HP\\source\\repos\\Project9\\Project9\\file.txt";
		argv[2] = "C:\\Users\\HP\\source\\repos\\Project9\\Project9\\result.txt";
	}


	// открыть файл для чтения
	fpin = fopen(argv[1], "rt");
	if (fpin == NULL)
	{
		printf("error1");
		return; // ошибка при открытии файла
	}
	 
    // открыть файл для записи
	fpout = fopen(argv[2], "wt");
	if (fpout == NULL)
	{
		printf("error2");
		return; // ошибка при открытии файла
	}

	while (!feof(fpin))// цикл до конца файла
	{
		in_ptr = fgets(line, MAXLINE, fpin); // получаем новую строку и ставим на нее указатель

		if (in_ptr == NULL)
		{
			break; // файл исчерпан
		}


		do
		{
			if (*in_ptr == ' ' || *in_ptr == '.' || *in_ptr == ',' || *in_ptr == '\n' || *in_ptr == '\0' || *in_ptr == '\t') // если текущий символ разделитель,
			{
				if (word == YES && cnt % 2 != 0 || symb == YES) // если проходит по 1/2 условию,
				{
					for (; word_ptr < in_ptr; word_ptr++, out_ptr++) // копируем слово до разделителя
					{
						*out_ptr = *word_ptr; // копирование
					}
				}
				else
				{
					word_ptr = word_ptr + cnt;
				}
				
				if (*in_ptr != '\0')
				{
					*out_ptr++ = *in_ptr; // вставляем текущий разделитель
				}

				symb = NO;
				word = NO;
				cnt = 0;
			}
			else
			{
				cnt++;
				if ((*in_ptr < 'a' || *in_ptr > 'z') && (*in_ptr < 'A' || *in_ptr > 'Z')) // проверить не является ли этот символ лишним
				{
					symb = YES; // в слове есть лишний символ
				}

				if (word == NO) // если слова ещё нет,
				{
					word_ptr = in_ptr; // запоминаем адрес первой буквы
				}
				word = YES;
			}
		} while (*in_ptr++ != '\0'); // продолжаем до конца строки
	}

	while (output_ptr != out_ptr)
	{
		fprintf(fpout, "%c", *output_ptr++);
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;

}
