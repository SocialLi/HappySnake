#pragma once  //ֻҪ��ͷ�ļ����ʼ��������ָ����ܹ���֤ͷ�ļ�������һ��   
#ifndef _SNAKE_H_    //#pragma once������ֹĳ��ͷ�ļ������include��#ifndef��#define��#endif������ֹĳ����(һ��Ԥ����ָ��)����ζ��塣
#define _SNAKE_H_    //#ifndef��#define��#endif�����C++������أ�����C++�����еĺ궨�壬ͨ���궨������ļ���α���
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)



#define FONT_WINDOW_STARTY 41 //�������崰��
#define FONT_WINDOW_STARTX 2
#define FRAME_HEIGHT 20 //�����ͼ��С
#define FRAME_WIDTH 40
#define UP 'w' //���������
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define SNAKE_LEN 50
#define ADD 3
#define IsProFood 1 //ʳ�����ߵ������Ƿ��غ� 


static int i, j, k;
static char ch = UP; //����ĵ�һ������
static char Direction = UP;
static int grow = 0; //��ǣ����Ƿ񳤴�  
static int ret = 0;
static int finish = 1;
static int score = 0;

//�ṹ����
struct Food{
	int x;
	int y;
};
struct Snake{
	int x[SNAKE_LEN];
	int y[SNAKE_LEN];
	int len;
	int speed;
}; 

 
//��ʼ���� 
void startbgm1();
void startbgm2();
void startbgm3();

//ֹͣ���� 
void stopbgm1();
void stopbgm2();
void stopbgm3();

//��ʼ����ͼ 
void initMap(void);

//����ʳ��
void updataFood(void);

//�ƶ��� 
void moveSnake(void);

//�ж����Ƿ����
int isAlive(void);

//�����ߵ��ٶ�
void getSpeed(void);

//�ƶ����
void gotoxy(int x, int y);

//��Ϸ������ұ߲��� 
void printFont(int x, int y, int speed);

//������Ϸǰ�Ľ���
int menu();


#endif
