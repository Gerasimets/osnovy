#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>

# define YES 1
# define NO 0
# define MAXLINE 1024

int main(void)
{
	// указатели на структуру типа FILE для входной и выходного файлов
	FILE *fpin;
	FILE *fpout;

	char line[MAXLINE]; // текущая строка
	char result[MAXLINE]; // результирующая строка
	char c; // текущий символ
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	int chetnoe = NO; // признак, что в слове четное кол-во букв
	int cnt = 0;// счетчик кол-ва букв в слове
	char *in_ptr = line; // указатель на текущий символ входной строки
	char *out_ptr = result; // указатель на текущий символ выходной строки
	char *word_ptr = line; // указатель на начало слова
	char *output_ptr = result; // указатель на результирующий масcив


	// открыть файл для чтения
	fpin = fopen("file.txt", "rt");
	if (fpin == NULL)
	{
		printf("error1");
		return; // ошибка при открытии файла
	}
	 
    // открыть файл для записи
	fpout = fopen("result.txt", "wt");
	if (fpout == NULL)
	{
		printf("error2");
		return; // ошибка при открытии файла
	}

	while (!feof(fpin))// цикл до конца файла
	{
		//cnt = 0; //перед новой строкой обнуляем счетчик на кол-во букв
		in_ptr = fgets(line, MAXLINE, fpin); // получаем новую строку и ставим на нее указатель

		if (in_ptr == NULL)
		{
			break; // файл исчерпан
		}


		do
		{
			c = *in_ptr; // берем текущий символ
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // если текущий символ разделитель,
			{
				if (word == YES && chetnoe == NO || symb == YES) // если проходит по 1/2 условию,
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
					*out_ptr++ = c; // вставляем текущий разделитель
				}

				symb = NO;
				word = NO;
				cnt = 0;
			}
			else
			{
				cnt++;
				if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
				{
					symb = YES; // в слове есть лишний символ
				}

				if (word == NO) // если слова ещё нет,
				{
					word_ptr = in_ptr; // запоминаем адрес первой буквы
				}

				if (cnt % 2 == 0) // если кол-во букв в слове чётное,
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

	while (output_ptr != out_ptr)
	{
		fprintf(fpout, "%c", *output_ptr++);
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;

}
