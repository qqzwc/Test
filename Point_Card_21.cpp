// Point_Card_21.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Point_Card_21.h"
#include <time.h>


//发牌函数的具体实现（函数定义）
void dealing( int* u_suit, int* u_point) {
	while (true)
	{
		
		int suit = rand() % 4;
		int point = rand() % 13;

		if ( mark[suit][point] == 0)
		{
			*u_suit = suit;
			*u_point = point;
			mark[suit][point] = 1;
			printf("成功发出一张牌\n");
			return;
		}
	}
	
}


//初始化用户手牌的实现（函数定义）
void init() {
	//设置随机数种子
	srand(time(NULL));

	printf("正在发牌！请稍等.....\n");
	dealing( &u1_suit[0], &u1_point[0]);
	dealing( &u1_suit[1], &u1_point[1]);
	n1 = 2;
	u1_sign = 'y';

	dealing( &u2_suit[0], &u2_point[0]);
	dealing( &u2_suit[1], &u2_point[1]);
	n2 = 2;
	u2_sign = 'y';
}


//打印用户的手牌的实现（函数定义）
void print(){
	printf("用户【1】的手牌：");
	for (int i = 0; i < n1; i++)
	{
		printf(" %s%s ", print_suit[u1_suit[i]], print_point[u1_point[i]]);
	}
	printf("\n");

	printf("用户【2】的手牌：");
	for (int i = 0; i < n2; i++)
	{
		printf(" %s%s ", print_suit[u2_suit[i]], print_point[u2_point[i]]);
	}
	printf("\n");
}


//游戏运行逻辑的实现（函数定义）
void playgame() {
	while (true)
	{
		//显示上一轮要牌之后的结果；

		print();

		if ( (u1_sign == 'n') && (u2_sign == 'n'))
		{
			return;
		}

		if ( u1_sign == 'y')
		{
			printf("用户【1】是否需要继续拿牌？\n");
			printf("需要请按 “y”\n");
			printf("不需要请按 “n”\n");
			printf("请输入你的选择：");
			scanf(" %c", &u1_sign);

			//清空输入缓冲区里的回车换行符
			scanf("%*[^\n]");
			scanf("%*c");

			//如果用户选择 y，需要再给他发一张牌 ？？？
			if ( u1_sign == 'y')
			{
				dealing( &u1_suit[n1], &u1_point[n1]);
				n1++;
			}
		}

		if (u2_sign == 'y')
		{
			printf("用户【2】是否需要继续拿牌？\n");
			printf("需要请按 “y”\n");
			printf("不需要请按 “n”\n");
			printf("请输入你的选择：");
			scanf(" %c", &u2_sign);

			//清空输入缓冲区里的回车换行符
			scanf("%*[^\n]");
			scanf("%*c");

			//如果用户选择 y，需要再给他发一张牌
			if (u2_sign == 'y')
			{
				dealing(&u2_suit[n2], &u2_point[n2]);
				n2++;
			}
		}
	}
}

//实现用户手牌点数计算的功能（函数定义）
void calculation_point_number() {

	if ((n1 == 2) && ( (u1_point[0] == 0) && (u1_point[1] == 0)))
	{
		u1_poker_points = point_num[u1_point[0]] + point_num[u1_point[1]] + 10;
	}

	if ((n1 == 2) && ( (u1_point[0] == 0) || (u1_point[1] == 0)))
	{
		u1_poker_points = point_num[u1_point[0]] + point_num[u1_point[1]] + 10;
	}

	if ((n1 == 2) && ( (u1_point[0] != 0) && (u1_point[1] != 0)))
	{
		u1_poker_points = point_num[u1_point[0]] + point_num[u1_point[1]];
	}

	if ((n2 == 2) && ((u2_point[0] == 0) && (u2_point[1] == 0)))
	{
		u2_poker_points = point_num[u2_point[0]] + point_num[u2_point[1]] + 10;
	}

	if ((n2 == 2) && ((u2_point[0] == 0) || (u2_point[1] == 0)))
	{
		u2_poker_points = point_num[u2_point[0]] + point_num[u2_point[1]] + 10;
	}

	if ((n2 == 2) && ((u2_point[0] != 0) && (u2_point[1] != 0)))
	{
		u2_poker_points = point_num[u2_point[0]] + point_num[u2_point[1]];
	}
	
	if ( n1>2)
	{
		for (int i = 0; i < n1; i++)
		{
			u1_poker_points += point_num[u1_point[i]];
		}
	}

	if ( n2>2)
	{
		for (int i = 0; i < n2; i++)
		{
			u2_poker_points += point_num[u2_point[i]];
		}
	}

	printf("用户【1】 = %d\n", u1_poker_points);
	printf("用户【2】 = %d\n", u2_poker_points);
}

//实现两个用户胜负判断（函数实现）
void judgement_of_victory_or_defeat() {

	if ( (u1_poker_points == 21) && (u2_poker_points != 21))
	{
		printf("用户【1】获胜！\n");
		return;
	}
	if ( (u1_poker_points != 21) && (u2_poker_points == 21))
	{
		printf("用户【2】获胜！\n");
		return;
	}
	if ( (u1_poker_points == 21) && (u2_poker_points == 21))
	{
		printf("平局！\n");
		return;
	}

	if ( (u1_poker_points <= 21) && (u2_poker_points > 21))
	{
		printf("用户【1】获胜！\n");
		return;
	}
	if ( (u1_poker_points > 21) && (u2_poker_points <= 21))
	{
		printf("用户【2】获胜！\n");
		return;
	}
	if ( (u1_poker_points > 21) && (u2_poker_points > 21))
	{
		printf("平局！\n");
		return;
	}

	if ( (u1_poker_points < 21) && (u2_poker_points < 21))
	{
		if ( u1_poker_points > u2_poker_points)
		{
			printf("用户【1】获胜！\n");
			return;
		}
		else if ( u1_poker_points < u2_poker_points)
		{
			printf("用户【2】获胜！\n");
			return;
		}
		else
		{
			printf("平局！\n");
			return;
		}
	}
}


int main()
{

	init();
	//print();
	playgame();
	calculation_point_number();
	judgement_of_victory_or_defeat();

	//int i = 0;
	//while ( i < Number)
	//{
	//	dealing( &u1_suit[i], &u1_point[i]);

	//	i++;

	//	/*u1_suit[i] = rand() % 4;
	//	u1_point[i] = rand() % 13;
	//	i++;*/
	//}

	//for (int i = 0; i < Number; i++)
	//{
	//	printf("%s%s ", print_suit[u1_suit[i]], print_point[u1_point[i]]);
	//}

	/*int suit = rand() % 4;

	int point = rand() % 13;

	int i = 0;
	while (i < 10) {
		suit = rand() % 4;
		point = rand() % 13;
		printf("%s%s\n", print_suit[suit], print_point[point]);
		i++;
	}*/
	

	system("pause");
    return 0;
}

