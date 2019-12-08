#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define N 200
#define YES 1
#define NO 0

typedef struct
{
	char title[N]; // название
	int game; // всего игр
	int victory; // всего побед
	int tie; // всего ничей
	int defeat; // всего поражений
	int points; // всего очков
	int goal; //всего голов
	int play; //играла команда или нет 
	int mas[N];
}liga;

liga team[N];
int number = 0;
int num;

int menu(void); 
void new_team(void);
void game(void);
void full(void);
void turnir(void);
void read(void);
void save(void);

int main()
{
	int a;
	while ((a = menu()) != 6)
	{
		switch (a)
		{
		case 1:
			new_team();
			break;
		case 2:
			game();
			break;
		case 3:
			full();
			break;
		case 4:
			turnir();
			break;
		case 5:
			read();
			break;
		};
	}
	return 0;
}

int menu(void)
{
	system("cls");
	int m;
	printf("Select menu item:\n");
	printf("1-New team\n"); // новая команда
	printf("2-New game\n"); // игра
	printf("3-Full table\n"); // полная таблица
	printf("4-Tournament table\n"); // турнирная таблица
	printf("5-\n");
	printf("6-Exit the program\n");
	scanf("%d", &m);
	system("cls");
	return m;
}

void new_team(void)
{
	/*int all[N];*/

	printf("Enter name > ");
	scanf("%s", team[number].title);

	team[number].game = 0;
	team[number].victory = 0;
	team[number].tie = 0;
	team[number].defeat = 0;
	team[number].points = 0;
	team[number].play = 0;
	team[number].goal = 0;
	team[number].mas[0] = number;

	number++;

	system("pause");

	save();
}

void game(void)
{
	int flag = NO;
	int found = NO;

	int player1;
	int player2;

	int gol1 = 0;
	int gol2 = 0;

	int i, j;

	srand(time(NULL));

	for (num = 0; num < number; num++)
	{
		if (team[num].play != number - 1)
		{
			found = YES;
		}

	}

	if (found == YES)
	{
		while (flag != YES)
		{
			player1 = 0 + rand() % number;
			player2 = 0 + rand() % number;

			flag = YES;

			for (i = 0; i <= team[player1].play/*+1*/ && flag == YES; i++) //и тут плюс 1
			{
				for (j = 0; j <= team[player2].play/*+1*/ && flag == YES; j++) //вот тут +1
				{
					if (team[player1].mas[i] == team[player2].mas[j])
					{
						flag = NO;
					}
				}
			}
		}

		if (flag == YES)
		{
			team[player1].play += 1;
			team[player2].play += 1;

			team[player1].mas[team[player1].play] = player2;
			team[player2].mas[team[player2].play] = player1;
		}

		printf("%s VS %s\n", team[player1].title, team[player2].title);

		printf("Enter score > ");
		scanf("%d:%d", &gol1, &gol2);

		team[player1].goal += gol1;
		team[player2].goal += gol2;

		if (gol1 > gol2) //если больше голов у первой команды
		{
			team[player1].game += 1; //плюс одна игра
			team[player1].victory += 1; //плюс одна победа
			team[player1].points += 3; //плюс три очка

			team[player2].game += 1; //плюс одна игра
			team[player2].defeat += 1; //плюс одно поражение
		}
		else if (gol1 < gol2) //если больше голов у второй команды
		{
			team[player2].game += 1; //плюс одна игра
			team[player2].victory += 1; //плюс одна победа
			team[player2].points += 3; //плюс три очка

			team[player1].game += 1; //плюс одна игра
			team[player1].defeat += 1; //плюс одно поражение
		}
		else //иначе, если количество очков одинаковое
		{
			team[player1].game += 1; //плюс одна игра
			team[player1].tie += 1; //одна ничья
			team[player1].points += 1; //одно очко

			team[player2].game += 1; //одна игра
			team[player2].tie += 1; //одна ничья
			team[player2].points += 1; //одно очко
		}

		save();
	}
	else
	{
		printf("The teams have already played\n"); //все команды уже сыграли
	}
	system("pause");
}

void full(void)
{
	for (num = 0; num < number; num++)
	{
		printf("\t%s %s %s %s %s %s %s\n", "TEAM", "MATCHES", "VICTORIES", "DEFEATS", "TIE", "GOALS", "POINTS");
		printf("\t%s \t%d \t%d \t%d \t%d    %d \t%d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points);
	}
	system("pause");
}

void turnir(void)
{
	liga Temp;

	for (num = 0; num < number - 1; num++)
	{
		for (int j = (number - 1); j > num; j--)
		{
			if (team[j - 1].points < team[j].points)
			{
				Temp = team[j - 1];
				team[j - 1] = team[j];
				team[j] = Temp;
			}
		}
	}

	for (num = 0; num < number; num++)
	{
		printf("\t%s %s\n", "TEAM", "POINTS");
		printf("\t%s %d\n", team[num].title, team[num].points);
	}
	system("pause");
}

void read(void)
{
	FILE* fpin = fopen("C:\\Users\\HP\\source\\file.txt", "rt"); // открыть входной файл для чтения

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		int i, j, k;
		char line[N];
		char* mas = line;
		char* ptr = fgets(line, N, fpin); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		for (i = 0, j = 0; line[i] != ' '; i++, j++)
		{
			team[number].title[j] = line[i];
		}

		mas = &line[++i];
		team[number].game = atoi(mas);

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].victory = atoi(mas);

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].tie = atoi(mas);

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].defeat = atoi(mas);

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].goal = atoi(mas);

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].points = atoi(mas);

		number++;
	}

	fclose(fpin); // закрыть входной файл

	save();
	full();
}

void save(void)
{
	FILE* fpout = fopen("C:\\Users\\HP\\source\\file.txt", "wt"); // открыть файл для записи

	if (fpout == NULL)
	{
		printf("error opening file output\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	for (num = 0; num < number; num++)
	{
		fprintf(fpout, "%s %d %d %d %d %d %d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points);
	}

	fclose(fpout); // закрыть выходной файл
}
