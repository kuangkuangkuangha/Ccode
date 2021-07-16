#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

int x = 0, y = 0;	//人的坐标

enum{UP,DOWN,LEFT,RIGHT};//方向

//地图
//数组、二维数组
int map[10][10] =
{
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 3, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 4, 1, 1, 1, 1, 0 },
	{ 1, 3, 0, 4, 2, 4, 0, 3, 1, 0 },
	{ 1, 1, 1, 1, 4, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 3, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 }
};

//获取人的坐标
void GetGamerPos()
{
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
			{
				x = i;
				y = j;
			}
		}
	}
}

//打印地图
void PrintMap()
{
	//清屏
	system("cls");

	/*推箱子*/
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (map[i][j])
			{
			case 0://空地
				printf("  ");
				break;
			case 1://墙
				printf("■");
				break;
			case 2://人
				printf("♀");
				break;
			case 3://目的地
				printf("☆");
				break;
			case 4://箱子
				printf("□");
				break;
			case 5://箱子和目的地重合
				printf("★");
				break;
			case 6://人站在目的地
				printf("♀");
				break;
			}
		}
		printf("\n");
	}
}

//运行行走
void Run(int direction)
{
	GetGamerPos();

	int d_x = 0;
	int d_y = 0;

	if (direction == UP)
	{
		d_x = -1;
		d_y = 0;
	}
	else if (direction == DOWN)
	{
		d_x = 1;
		d_y = 0;
	}
	else if (direction == LEFT)
	{
		d_x = 0;
		d_y = -1;
	}
	else if (direction == RIGHT)
	{
		d_x = 0;
		d_y = 1;
	}

	//1.人的前面是空地
	if (map[x + d_x * 1][y + d_y * 1] == 0)
	{
		map[x + d_x * 1][y + d_y * 1] = 2;

		if (map[x][y] == 2)
		{
			map[x][y] = 0;
		}
		else
		{
			map[x][y] = 3;
		}
	}

	//2.人的前面是目的地
	else if (map[x + d_x * 1][y + d_y * 1] == 3)
	{
		map[x + d_x * 1][y + d_y * 1] = 6;
		if (map[x][y] == 2)
		{
			map[x][y] = 0;
		}
		else
		{
			map[x][y] = 3;
		}
	}
	//3.人的前面是箱子
	else if (map[x + d_x * 1][y + d_y * 1] == 4)
	{
		//a.箱子的前面是空地
		if (map[x + d_x * 2][y + d_y * 2] == 0)
		{
			map[x + d_x * 2][y + d_y * 2] = 4;
			map[x + d_x * 1][y + d_y * 1] = 2;

			if (map[x][y] == 2)
			{
				map[x][y] = 0;
			}
			else
			{
				map[x][y] = 3;
			}

		}
		//b.箱子的前面是目的地
		else if (map[x + d_x * 2][y + d_y * 2] == 3)
		{
			map[x + d_x * 2][y + d_y * 2] = 5;
			map[x + d_x * 1][y + d_y * 1] = 2;

			if (map[x][y] == 2)
			{
				map[x][y] = 0;
			}
			else
			{
				map[x][y] = 3;
			}
		}
	}
	//4.人的前面是箱子和目的地重合
	else if (map[x + d_x * 1][y + d_y * 1] == 5)
	{
		//a.箱子和目的地重合的前面是空地
		if (map[x + d_x * 2][y + d_y * 2] == 0)
		{
			map[x + d_x * 2][y + d_y * 2] = 4;
			map[x + d_x * 1][y + d_y * 1] = 6;

			if (map[x][y] == 2)
			{
				map[x][y] = 0;
			}
			else
			{
				map[x][y] = 3;
			}
		}
		//b.箱子和目的地重合的前面是目的地
		else if (map[x + d_x * 2][y + d_y * 2] == 3)
		{
			map[x + d_x * 2][y + d_y * 2] = 5;
			map[x + d_x * 1][y + d_y * 1] = 6;

			if (map[x][y] == 2)
			{
				map[x][y] = 0;
			}
			else
			{
				map[x][y] = 3;
			}
		}
	}
}


int main()
{
	while (1)
	{
		//打印地图
		PrintMap();

		//getchar();//读取一个字符
		char ch = getchar();

		switch (ch)
		{
		case 'w':
		case 72:
			Run(UP);
			break;
		case 's':
		case 80:
			Run(DOWN);
			break;
		case 'a':
		case 75:
			Run(LEFT);
			break;
		case 'd':
		case 77:
			Run(RIGHT);
			break;
		}
	}

	return 0;
}