#include "functions.h"

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
