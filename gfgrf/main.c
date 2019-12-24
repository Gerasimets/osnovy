#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define N 100
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
	int goal; // всего голов
	int play;
	int mas[N];
}liga;

liga* team;
int number = 0;
int num;
int cnt;

int menu(void);
void new_team(void);
void game(void);
void full(void);
void turnir(void);
void read(void);
void save(void);
int factorial(int);
void count(void);

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
		default:
			printf("Select menu item\n");
			system("pause");
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
	printf("5-Load from file\n");
	printf("6-Exit the program\n");
	scanf("%d", &m);
	system("cls");
	return m;
}

void new_team(void)
{
	FILE* fpout = fopen("C:\\Users\\User\\source\\repos\\gerf.txt", "a"); // открыть файл для записи
	count();
	team = (liga*)realloc(team, (++cnt) * sizeof(liga));

	printf("Enter name > ");
	scanf("%s", &team[number].title);
	fprintf(fpout, "%s ", team[number].title);

	team[number].game = 0;
	fprintf(fpout, "%d ", team[number].game);
	team[number].victory = 0;
	fprintf(fpout, "%d ", team[number].victory);
	team[number].tie = 0;
	fprintf(fpout, "%d ", team[number].tie);
	team[number].defeat = 0;
	fprintf(fpout, "%d ", team[number].defeat);
	team[number].points = 0;
	fprintf(fpout, "%d ", team[number].points);
	team[number].play = 0;
	fprintf(fpout, "%d ", team[number].play);
	team[number].goal = 0;
	fprintf(fpout, "%d ", team[number].goal);
	fprintf(fpout, "\n");

	fclose(fpout); // закрыть выходной файл
	number++;

	system("pause");
}

void game(void)
{
	int found_new_players = NO;
	int unplayed = NO;
	int finish_found = NO;

	int player1;
	int player2;

	int gol1 = 0;
	int gol2 = 0;

	int i, j, r;

	srand(time(NULL));

	int pot = factorial(number) / (factorial(number - 2) * 2);

	for (num = 0; num < number; num++)
	{
		if (team[num].play != number - 1)
		{
			unplayed = YES;
		}
	}

	if (unplayed == YES)
	{
		while (found_new_players != YES)
		{
			found_new_players = YES;

			while (finish_found != YES)
			{
				player1 = 0 + rand() % number;
				player2 = 0 + rand() % number;

				if (player1 != player2)
				{
					finish_found = YES;
				}
			}

			if (team[player1].play == 0)
			{
				for (r = 0; r < number - 1; r++)
				{
					team[player1].mas[r] = -1;
				}
			}

			if (team[player2].play == 0)
			{
				for (r = 0; r < number - 1; r++)
				{
					team[player2].mas[r] = -1;
				}
			}

			for (int i = 0; i < number - 1; i++)
			{
				if (team[player1].mas[i] == player2)
				{
					found_new_players = NO;
					finish_found = NO;
				}
			}
		}

		team[player1].mas[team[player1].play] = player2;
		team[player2].mas[team[player2].play] = player1;

		team[player1].play += 1;
		team[player2].play += 1;

		printf("%s VS %s\n", team[player1].title, team[player2].title);

		printf("Enter score > ");
		scanf("%d:%d", &gol1, &gol2);

		team[player1].goal += gol1;
		team[player2].goal += gol2;

		if (gol1 > gol2)
		{
			team[player1].game += 1;
			team[player1].victory += 1;
			team[player1].points += 3;

			team[player2].game += 1;
			team[player2].defeat += 1;
		}
		else if (gol1 < gol2)
		{
			team[player2].game += 1;
			team[player2].victory += 1;
			team[player2].points += 3;

			team[player1].game += 1;
			team[player1].defeat += 1;
		}
		else
		{
			team[player1].game += 1;
			team[player1].tie += 1;
			team[player1].points += 1;

			team[player2].game += 1;
			team[player2].tie += 1;
			team[player2].points += 1;
		}

		save();
	}
	else
	{
		printf("The teams have already played\n");
	}

	system("pause");
}

void full(void)
{
	for (num = 0; num < number; num++)
	{
		printf("\t%s %s %s %s %s %s %s\n", "TEAM", "MATCHES", "VICTORIES", "DEFEATS", "TIE", "GOALS", "POINTS");
		printf("\t%s \t%d \t%d \t%d \t%d    %d      %d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points);
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
		printf("\t%s \t%d\n", team[num].title, team[num].points);
	}
	system("pause");
}

void read(void)
{
	count();
	team = (liga*)malloc(cnt * sizeof(liga));
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\gerf.txt", "rt"); // открыть входной файл для чтения

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
		team[number].title[j] = '\0';

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

		for (i++; line[i] != ' '; i++)
		{

		}

		mas = &line[++i];
		team[number].play = atoi(mas);

		number++;
	}

	fclose(fpin); // закрыть входной файл

	full();
}

void save(void)
{
	FILE* fpout = fopen("C:\\Users\\User\\source\\repos\\gerf.txt", "wt"); // открыть файл для записи

	if (fpout == NULL)
	{
		printf("error opening file output\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	for (num = 0; num < number; num++)
	{
		fprintf(fpout, "%s %d %d %d %d %d %d %d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points, team[num].play);
	}

	fclose(fpout); // закрыть выходной файл
}

int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

void count(void)
{
	cnt = 0;
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\gerf.txt", "rt"); // открыть файл для записи

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		char line[N];
		char* ptr = fgets(line, N, fpin); // чтение строки
		int i = 0;

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		i = 0;

		while (line[i] != '\n')
		{
			i++;
		}
		cnt++;
	}

	fclose(fpin); // закрыть входной файл
}
