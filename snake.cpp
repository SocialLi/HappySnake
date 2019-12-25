#include "snake.h"

//初始化结构体 
struct Food food;
struct Snake snake;


//开始音乐
void startbgm1()   //插入音乐需用到 mciSendString()函数，且需要#include <windows.h>、#include <mmsystem.h>、#pragma comment(lib, "Winmm.lib") 这三个头文件才可以使用函数 
{
	mciSendString("open 123.mp3 alias bgm1", NULL, 0, NULL);
	mciSendString("play bgm1 repeat", NULL, 0, NULL);	
}
void startbgm2()
{
	mciSendString("open eat.mp3 alias bgm2", NULL, 0, NULL);
	mciSendString("play bgm2 repeat", NULL, 0, NULL);	
}
void startbgm3()
{
	mciSendString("open die.mp3 alias bgm3", NULL, 0, NULL);
	mciSendString("play bgm3 repeat", NULL, 0, NULL);	
}
//停止音乐 
void stopbgm1()
{
	mciSendString("stop bgm1", NULL, 0, NULL);
	mciSendString("close 123.mp3", NULL, 0, NULL);
}
void stopbgm2()
{
	mciSendString("stop bgm2", NULL, 0, NULL);
	mciSendString("close eat.mp3", NULL, 0, NULL);
}
void stopbgm3()
{
	mciSendString("stop bgm3", NULL, 0, NULL);
	mciSendString("close die.mp3", NULL, 0, NULL);
}

//进入游戏前的界面 
int menu()
{
	gotoxy(14, 45);  //gotoxy()函数在<windows.h>中 
	printf("欢迎来到贪吃蛇小游戏....");
	gotoxy(16, 45);
	printf("开始游戏请按Enter键");
	gotoxy(18, 45);
	printf("按其他任意键退出游戏");
	int ch = getch();

	while (TRUE)
	{
		if (ch == 13)									//Enter键的ASCII值为13 
		{
			ret = 1;
			break;
		}
		else
		{
			break;
		}


	}
	system("cls");
	return ret;
}

//初始化地图 
void initMap(void)
{
	ch = UP;
	Direction = UP;
	//最初的食物
	srand(time(NULL));							//设置随机数种子，需引入<stdlib.h> 
	food.x = rand() % (FRAME_HEIGHT - 2) + 1;
	food.y = rand() % (FRAME_WIDTH/2 - 2) + 1;
	gotoxy(food.x, food.y*2);
	printf("★");
	//最初的蛇
	snake.x[0] = FRAME_HEIGHT / 2;
	snake.y[0] = FRAME_WIDTH / 4;
	gotoxy(snake.x[0], snake.y[0]*2);
	printf("■");
	snake.len = 3;
	snake.speed = 200;
	for (k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1] + 1;
		snake.y[k] = snake.y[k - 1];
		gotoxy(snake.x[k], snake.y[k]*2);
		printf("■");
	}
	//墙
	for (j = 0; j < FRAME_WIDTH/2; j++)
	{
		gotoxy(0, j*2);
		printf("■");
		gotoxy(FRAME_HEIGHT - 1, j*2);
		printf("■");
	}
	for (i = 1; i < FRAME_HEIGHT - 1; i++)
	{
		gotoxy(i, 0);
		printf("■");
		gotoxy(i, (FRAME_WIDTH/2 - 1)*2);
		printf("■");
	}
}

//游戏界面的右边部分 
void printFont(int x, int y, int speed)
{
	int i = 1;
	gotoxy(x, y);
	printf("召唤师,欢迎来到贪吃蛇峡谷");

	gotoxy(x + ADD, y);
	if (speed == 300)
	{
		printf("现在的速度是：%d级", i);
	}
	else if (speed == 200)
	{
		printf("现在的速度等级是:%d级", i + 1);
	}
	else if (speed == 100)
	{
		printf("现在的速度等级是:%d级", i + 2);
	}
	else
	{
		printf("恭喜你，召唤师，现在是最高级");
	}
	
	gotoxy(x + 2 * ADD, y);
	printf("分数：%d",score);
	
	gotoxy(x + 3 * ADD, y);
	printf("上下左右操作键分别是：w,s,a,d");

	gotoxy(x + 4 * ADD, y);
	printf("当吃到自己身体或者撞墙时游戏结束");

	gotoxy(x + 5 * ADD, y);
	printf("按空格键暂停，在按空格键继续");
}

//更新食物 
void updataFood()
{
	if (snake.x[0] == food.x&&snake.y[0] == food.y)				//当蛇吃到食物的时候 
	{
		srand(time(NULL));
		while(1)
		{
			food.x = rand() % (FRAME_HEIGHT - 2) + 1;
			food.y = rand() % (FRAME_WIDTH/2 - 2) + 1;
			int flag = 1, i;
			for(i = 0; i < snake.len; i++)
			{
				if(snake.x[i] == food.x && snake.y[i] == food.y)
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				break;	
		}
		gotoxy(food.x, food.y*2);
		printf("★");


		snake.len++;
		grow = 1;
		startbgm2();
		score ++;
	}
	else stopbgm2();
}

//移动蛇 
void moveSnake()
{

	if (!grow)
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]*2);
		printf(" ");							//蛇尾将会是空的 
	}
	for (k = snake.len - 1; k>0; k--)
	{
		snake.x[k] = snake.x[k - 1];
		snake.y[k] = snake.y[k - 1];
	}
	if (kbhit())    //C语言中kbhit()函数（conio.h）：检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
	{
		ch = getch();
		if (ch == ' ')												//按空格暂停或继续
		while (getch() != ' '){};
		if (ch != UP && ch != DOWN && ch != LEFT && ch != RIGHT)	//防止其他按键的干扰
		{
			ch = Direction;
			goto sport;
		}

		if (Direction != ch)
		{
			if ((Direction == UP &&ch != DOWN) || (Direction == DOWN &&ch != UP) || (Direction == LEFT && ch != RIGHT) || (Direction == RIGHT && ch != LEFT)) //防止反向运动
			{
				Direction = ch;
				goto sport;
			}
			else
			{
				ch = Direction;
				goto sport;
			}

		}
		else
		{
			goto sport;
		}
	}
	else
	{
	sport:
		switch (ch)							//移动蛇的头 
		{
		case UP: snake.x[0]--; break;
		case DOWN:  snake.x[0]++; break;
		case LEFT: snake.y[0]--; break;
		case RIGHT: snake.y[0]++; break;
		default: break;

		}
	}

	gotoxy(snake.x[0], snake.y[0]*2);
	printf("■");							//打印蛇的头 
	grow = 0;
	gotoxy(FRAME_HEIGHT, 0);
}

//判断蛇是否活着 
int isAlive(void)
{
	if (snake.x[0] == 0 || snake.x[0] == FRAME_HEIGHT - 1 || snake.y[0] == FRAME_WIDTH/2 - 1 || snake.y[0] == 0)   //当你碰到墙或者吃掉自己的身体，你就会死
		return 0;
	for (k = 1; k<snake.len; k++)
	if (snake.x[k] == snake.x[0] && snake.y[k] == snake.y[0])
		return 0;
	return 1;
}

//更新蛇的速度 
void getSpeed(void)
{
	if (snake.len <= 6)
		snake.speed = 300;
	else if (snake.len <= 10)
		snake.speed = 200;
	else if (snake.len <= 20)
		snake.speed = 100;
	else if (snake.len <= 30)
		snake.speed = 50;
	else snake.speed = 20;
	if (snake.len == 40)
		finish = 0;
}

//移动光标
void gotoxy(int x, int y)
{
	HANDLE hout;								//定义处理对象
	COORD cor;									//定义坐标对象 
	/*
		COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：

    typedef struct _COORD {

    SHORT X; // 水平坐标 

    SHORT Y; // 垂直坐标
    } COORD;
	*/
	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//获取输出屏幕缓冲区的句柄
	cor.X = y;
	cor.Y = x;
	SetConsoleCursorPosition(hout, cor);		//Move Cursor  
}
