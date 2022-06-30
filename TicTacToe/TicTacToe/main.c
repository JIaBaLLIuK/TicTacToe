#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

char gameBoard[3][3];

void ResetBoard();
void PrintBoard();
void PlayerMove(char);
void ComputerMove();
char CheckWinner();
int CheckFreeSpace();
int InputAndCheck(int, int);
void PrintWinner(char);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isFinishedGame = false;
	do
	{
		system("CLS");
		int freeCells;
		char winner = ' ';
		printf("Выберите действие:\n1. Игра с компьютером.\n2. Игра с другим человеком.\n0. Завершить работу.\n");
		int gameType = InputAndCheck(0, 2);
		switch (gameType)
		{
		case 1:
		{
			int stopPlayingWithBot = 0;
			do
			{
				system("CLS");
				ResetBoard();
				do
				{
					system("CLS");
					printf("Ход компьютера...\n");
					Sleep(250);
					ComputerMove();
					PrintBoard();
					winner = CheckWinner();
					if (winner == 'O' || winner == 'X')
					{
						PrintWinner(winner);
						break;
					}
					freeCells = CheckFreeSpace();
					if (freeCells == 0)
					{
						winner = CheckWinner();
						PrintWinner(winner);
						break;
					}
					printf("Ваш ход!\n");
					PlayerMove('X');
					PrintBoard();
					winner = CheckWinner();
					if (winner == 'O' || winner == 'X')
					{
						PrintWinner(winner);
						break;
					}
					freeCells = CheckFreeSpace();
					if (freeCells == 0)
					{
						winner = CheckWinner();
						PrintWinner(winner);
						break;
					}
				} while (freeCells > 0);
				printf("Повторить игру с компьютером?\n0 - да\n1 - нет\n");
				stopPlayingWithBot = InputAndCheck(0, 1);
			} while (!stopPlayingWithBot);
			break;
		}
		case 2:
		{
			int stopPlayingWithPerson = 0;
			do
			{
				system("CLS");
				ResetBoard();
				do
				{
					printf("Ход игрока \"O\"!\n");
					PlayerMove('O');
					PrintBoard();
					winner = CheckWinner();
					if (winner == 'O' || winner == 'X')
					{
						PrintWinner(winner);
						break;
					}
					freeCells = CheckFreeSpace();
					if (freeCells == 0)
					{
						winner = CheckWinner();
						PrintWinner(winner);
						break;
					}
					printf("Ход игрока \"X\"!\n");
					PlayerMove('X');
					PrintBoard();
					winner = CheckWinner();
					if (winner == 'O' || winner == 'X')
					{
						PrintWinner(winner);
						break;
					}
					freeCells = CheckFreeSpace();
					if (freeCells == 0)
					{
						winner = CheckWinner();
						PrintWinner(winner);
						break;
					}
				} while (freeCells > 0);
				printf("Повторить игру с человеком?\n0 - да\n1 - нет\n");
				stopPlayingWithPerson = InputAndCheck(0, 1);
			} while (!stopPlayingWithPerson);
			break;
		}
		case 0:
			isFinishedGame = true;
			break;
		}
	} while (!isFinishedGame);
	return 0;
}

int InputAndCheck(int minValue, int maxValue)
{
	int number, check;
	check = scanf_s("%d", &number);
	while (!check || number < minValue || number > maxValue)
	{
		rewind(stdin);
		printf("Ошибка! Повторите ввод:\n");
		check = scanf_s("%d", &number);
	}
	return number;
}

void ResetBoard()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			gameBoard[i][j] = ' ';
}

void PrintBoard()
{
	printf(" %c | %c | %c ", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
	printf("\n");
}

int CheckFreeSpace()
{
	int freeCells = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (gameBoard[i][j] == ' ')
				freeCells++;
	return freeCells;
}
char CheckWinner()
{
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[2][2] != ' ')
		return gameBoard[0][0];
	if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ')
		return gameBoard[1][1];
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ')
			return gameBoard[1][i];
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ')
			return gameBoard[i][1];
	}
}

void PrintWinner(char winner)
{
	if (winner == 'O' || winner == 'X')
		printf("Игрок \"%c\" победил!\n", winner);
	else
		printf("Ничья!\n");
}

void ComputerMove()
{
	srand(time(NULL));
	int x, y;
	do
	{
		x = rand() % 3;
		y = rand() % 3;
	} while (gameBoard[x][y] != ' ');
	gameBoard[x][y] = 'O';
}

void PlayerMove(char player)
{
	int x, y;
	do
	{
		printf("Введите номер строки (1 - 3):\n");
		x = InputAndCheck(1, 3);
		printf("Введите номер столбца (1 - 3):\n");
		y = InputAndCheck(1, 3);
	} while (gameBoard[x - 1][y - 1] != ' ');
	gameBoard[x - 1][y - 1] = player;
}