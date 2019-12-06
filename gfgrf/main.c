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
	int goal;
	int play;
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
	printf("1-\n"); // новая команда
	printf("2-\n"); // игра
	printf("3-\n"); // полная таблица
	printf("4-\n"); // турнирная таблица
	printf("5-\n");
	printf("6-Exit the program\n");
	scanf("%d", &m);
	system("cls");
	return m;
}

void new_team(void)
{
	int all[N];

	printf("Enter name > ");
	scanf("%s", team[number].title);

	team[number].game = 0;
	team[number].victory = 0;
	team[number].tie = 0;
	team[number].defeat = 0;
	team[number].points = 0;
	team[number].play = 0;
	team[number].goal = 0;

	number++;

	system("pause");

	save();
}

void game(void)
{
	int flag = NO;

	int player1;
	int player2;

	int gol1 = 0;
	int gol2 = 0;

	srand(time(NULL));

	while (flag != YES)
	{
		player1 = 0 + rand() % number;

		if (team[player1].play == 0)
		{
			flag = YES;
			team[player1].play = 1;
		}
	}

	flag = NO;

	while (flag != YES)
	{
		player2 = 0 + rand() % number;

		if (team[player2].play == 0);
		{
			flag = YES;
			team[player2].play = 1;
		}
	}

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

void full(void)
{
	for (num = 0; num < number; num++)
	{
		printf("%s %d %d %d %d %d %d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points);
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
		printf("%s %d\n", team[num].title, team[num].points);
	}
	system("pause");
}

void read(void)
{
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

		mas = &line[++i];
		team[number].game = atoi(mas);

		mas = &line[++i];
		team[number].victory = atoi(mas);

		mas = &line[++i];
		team[number].tie = atoi(mas);

		mas = &line[++i];
		team[number].defeat = atoi(mas);

		mas = &line[++i];
		team[number].points = atoi(mas);

		mas = &line[++i];
		team[number].goal = atoi(mas);

		mas = &line[++i];
		team[number].play = atoi(mas);

		number++;
	}

	save();

	fclose(fpin); // закрыть входной файл
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
		fprintf(fpout, "%s %d %d %d %d %d %d\n", team[num].title, team[num].game, team[num].victory, team[num].defeat, team[num].tie, team[num].goal, team[num].points);
	}

	fclose(fpout); // закрыть выходной файл
}