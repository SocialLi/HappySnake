#pragma once  //只要在头文件的最开始加入这条指令就能够保证头文件被编译一次   
#ifndef _SNAKE_H_    //#pragma once用来防止某个头文件被多次include，#ifndef，#define，#endif用来防止某个宏(一种预处理指令)被多次定义。
#define _SNAKE_H_    //#ifndef，#define，#endif这个是C++语言相关，这是C++语言中的宏定义，通过宏定义避免文件多次编译
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)



#define FONT_WINDOW_STARTY 41 //定义字体窗口
#define FONT_WINDOW_STARTX 2
#define FRAME_HEIGHT 20 //定义地图大小
#define FRAME_WIDTH 40
#define UP 'w' //定义操作键
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define SNAKE_LEN 50
#define ADD 3
#define IsProFood 1 //食物与蛇的身体是否重合 


static int i, j, k;
static char ch = UP; //最初的第一个方向
static char Direction = UP;
static int grow = 0; //标记：蛇是否长大  
static int ret = 0;
static int finish = 1;
static int score = 0;

//结构声明
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

 
//开始音乐 
void startbgm1();
void startbgm2();
void startbgm3();

//停止音乐 
void stopbgm1();
void stopbgm2();
void stopbgm3();

//初始化地图 
void initMap(void);

//更新食物
void updataFood(void);

//移动蛇 
void moveSnake(void);

//判断蛇是否活着
int isAlive(void);

//更新蛇的速度
void getSpeed(void);

//移动光标
void gotoxy(int x, int y);

//游戏界面的右边部分 
void printFont(int x, int y, int speed);

//进入游戏前的界面
int menu();


#endif
