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
		player1_move(board, ROWS, COLS);           //���1����
		if ((ret = Is_win(board, ROWS, COLS)) != ' ')
			break;
		Display_board(board, ROWS, COLS);           //��ӡ����
		/*computer_move(board, ROWS, COLS);*/       //��������
		player2_move(board, ROWS, COLS);            //���2����
		if ((ret = Is_win(board, ROWS, COLS)) != ' ')   //�ж��Ƿ�Ӯ
			break;
		Display_board(board, ROWS, COLS);
	}
	if (ret == 'W')
		printf("���1Ӯ\n");
	else if (ret == 'X')
		printf("��Ҷ�Ӯ\n");
	else if (ret == 'Q')
		printf("ƽ��\n");
	/*Display_board(board, ROWS, COLS);*/
}
void menu()
{
	printf("####################\n");
	printf("##1��play##0��exit##\n");           //ѡ����Ϸ�����˳�
	printf("####################\n");
}
int main()
{
	int input = 0;
	menu();
	do
	{
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}

