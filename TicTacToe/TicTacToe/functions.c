#include "functions.h"

int InputAndCheck(int minValue, int maxValue)
{
	int number, check;
	check = scanf_s("%d", &number);
	while (!check || number < minValue || number > maxValue)
	{
		rewind(stdin);
		printf("������! ��������� ����:\n");
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
		printf("����� \"%c\" �������!\n", winner);
	else
		printf("�����!\n");
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
		printf("������� ����� ������ (1 - 3):\n");
		x = InputAndCheck(1, 3);
		printf("������� ����� ������� (1 - 3):\n");
		y = InputAndCheck(1, 3);
	} while (gameBoard[x - 1][y - 1] != ' ');
	gameBoard[x - 1][y - 1] = player;
}
