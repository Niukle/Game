#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"game.h"
#include<time.h>
void game()
{
	char board[ROWS][COLS];
	char ret = 0;
	init_board(board, ROWS, COLS);
	srand((unsigned int)time(NULL));
	while (1)
	{
		player1_move(board, ROWS, COLS);           //玩家1落子
		if ((ret = Is_win(board, ROWS, COLS)) != ' ')
			break;
		Display_board(board, ROWS, COLS);           //打印棋盘
		/*computer_move(board, ROWS, COLS);*/       //电脑落子
		player2_move(board, ROWS, COLS);            //玩家2落子
		if ((ret = Is_win(board, ROWS, COLS)) != ' ')   //判断是否赢
			break;
		Display_board(board, ROWS, COLS);
	}
	if (ret == 'W')
		printf("玩家1赢\n");
	else if (ret == 'X')
		printf("玩家二赢\n");
	else if (ret == 'Q')
		printf("平局\n");
	/*Display_board(board, ROWS, COLS);*/
}
void menu()
{
	printf("####################\n");
	printf("##1、play##0、exit##\n");           //选择游戏还是退出
	printf("####################\n");
}
int main()
{
	int input = 0;
	menu();
	do
	{
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

