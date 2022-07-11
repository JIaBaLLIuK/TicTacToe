#pragma once

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
