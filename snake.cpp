#include "snake.h"

//��ʼ���ṹ�� 
struct Food food;
struct Snake snake;


//��ʼ����
void startbgm1()   //�����������õ� mciSendString()����������Ҫ#include <windows.h>��#include <mmsystem.h>��#pragma comment(lib, "Winmm.lib") ������ͷ�ļ��ſ���ʹ�ú��� 
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
//ֹͣ���� 
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

//������Ϸǰ�Ľ��� 
int menu()
{
	gotoxy(14, 45);  //gotoxy()������<windows.h>�� 
	printf("��ӭ����̰����С��Ϸ....");
	gotoxy(16, 45);
	printf("��ʼ��Ϸ�밴Enter��");
	gotoxy(18, 45);
	printf("������������˳���Ϸ");
	int ch = getch();

	while (TRUE)
	{
		if (ch == 13)									//Enter����ASCIIֵΪ13 
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

//��ʼ����ͼ 
void initMap(void)
{
	ch = UP;
	Direction = UP;
	//�����ʳ��
	srand(time(NULL));							//������������ӣ�������<stdlib.h> 
	food.x = rand() % (FRAME_HEIGHT - 2) + 1;
	food.y = rand() % (FRAME_WIDTH/2 - 2) + 1;
	gotoxy(food.x, food.y*2);
	printf("��");
	//�������
	snake.x[0] = FRAME_HEIGHT / 2;
	snake.y[0] = FRAME_WIDTH / 4;
	gotoxy(snake.x[0], snake.y[0]*2);
	printf("��");
	snake.len = 3;
	snake.speed = 200;
	for (k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1] + 1;
		snake.y[k] = snake.y[k - 1];
		gotoxy(snake.x[k], snake.y[k]*2);
		printf("��");
	}
	//ǽ
	for (j = 0; j < FRAME_WIDTH/2; j++)
	{
		gotoxy(0, j*2);
		printf("��");
		gotoxy(FRAME_HEIGHT - 1, j*2);
		printf("��");
	}
	for (i = 1; i < FRAME_HEIGHT - 1; i++)
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, (FRAME_WIDTH/2 - 1)*2);
		printf("��");
	}
}

//��Ϸ������ұ߲��� 
void printFont(int x, int y, int speed)
{
	int i = 1;
	gotoxy(x, y);
	printf("�ٻ�ʦ,��ӭ����̰����Ͽ��");

	gotoxy(x + ADD, y);
	if (speed == 300)
	{
		printf("���ڵ��ٶ��ǣ�%d��", i);
	}
	else if (speed == 200)
	{
		printf("���ڵ��ٶȵȼ���:%d��", i + 1);
	}
	else if (speed == 100)
	{
		printf("���ڵ��ٶȵȼ���:%d��", i + 2);
	}
	else
	{
		printf("��ϲ�㣬�ٻ�ʦ����������߼�");
	}
	
	gotoxy(x + 2 * ADD, y);
	printf("������%d",score);
	
	gotoxy(x + 3 * ADD, y);
	printf("�������Ҳ������ֱ��ǣ�w,s,a,d");

	gotoxy(x + 4 * ADD, y);
	printf("���Ե��Լ��������ײǽʱ��Ϸ����");

	gotoxy(x + 5 * ADD, y);
	printf("���ո����ͣ���ڰ��ո������");
}

//����ʳ�� 
void updataFood()
{
	if (snake.x[0] == food.x&&snake.y[0] == food.y)				//���߳Ե�ʳ���ʱ�� 
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
		printf("��");


		snake.len++;
		grow = 1;
		startbgm2();
		score ++;
	}
	else stopbgm2();
}

//�ƶ��� 
void moveSnake()
{

	if (!grow)
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]*2);
		printf(" ");							//��β�����ǿյ� 
	}
	for (k = snake.len - 1; k>0; k--)
	{
		snake.x[k] = snake.x[k - 1];
		snake.y[k] = snake.y[k - 1];
	}
	if (kbhit())    //C������kbhit()������conio.h������鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
	{
		ch = getch();
		if (ch == ' ')												//���ո���ͣ�����
		while (getch() != ' '){};
		if (ch != UP && ch != DOWN && ch != LEFT && ch != RIGHT)	//��ֹ���������ĸ���
		{
			ch = Direction;
			goto sport;
		}

		if (Direction != ch)
		{
			if ((Direction == UP &&ch != DOWN) || (Direction == DOWN &&ch != UP) || (Direction == LEFT && ch != RIGHT) || (Direction == RIGHT && ch != LEFT)) //��ֹ�����˶�
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
		switch (ch)							//�ƶ��ߵ�ͷ 
		{
		case UP: snake.x[0]--; break;
		case DOWN:  snake.x[0]++; break;
		case LEFT: snake.y[0]--; break;
		case RIGHT: snake.y[0]++; break;
		default: break;

		}
	}

	gotoxy(snake.x[0], snake.y[0]*2);
	printf("��");							//��ӡ�ߵ�ͷ 
	grow = 0;
	gotoxy(FRAME_HEIGHT, 0);
}

//�ж����Ƿ���� 
int isAlive(void)
{
	if (snake.x[0] == 0 || snake.x[0] == FRAME_HEIGHT - 1 || snake.y[0] == FRAME_WIDTH/2 - 1 || snake.y[0] == 0)   //��������ǽ���߳Ե��Լ������壬��ͻ���
		return 0;
	for (k = 1; k<snake.len; k++)
	if (snake.x[k] == snake.x[0] && snake.y[k] == snake.y[0])
		return 0;
	return 1;
}

//�����ߵ��ٶ� 
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

//�ƶ����
void gotoxy(int x, int y)
{
	HANDLE hout;								//���崦�����
	COORD cor;									//����������� 
	/*
		COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��

    typedef struct _COORD {

    SHORT X; // ˮƽ���� 

    SHORT Y; // ��ֱ����
    } COORD;
	*/
	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//��ȡ�����Ļ�������ľ��
	cor.X = y;
	cor.Y = x;
	SetConsoleCursorPosition(hout, cor);		//Move Cursor  
}
