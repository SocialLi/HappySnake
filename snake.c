#include "snake.cpp"

//转置结构对象
extern  struct Food food;  //extern用在变量或函数的声明前，用来说明“此变量/函数是在别处定义的，要在此处引用” 
extern  struct Snake snake;

//主函数
int main()
{
	ret = menu();
	if (ret == 1)
	{
		while (finish)
		{
			initMap();																	//初始化地图 
			while (TRUE)
			{
				stopbgm3();
				startbgm1();
				updataFood();														//更新食物 
				getSpeed(); 													//速度 
				moveSnake();														//移动蛇 
				Sleep(snake.speed);									//使用sleep()函数将程序阻塞,控制蛇的速度,在<windows.h>中 
				printFont(FONT_WINDOW_STARTX, FONT_WINDOW_STARTY, snake.speed);		//右边窗口 
				if (!(isAlive()))
						break;
					
			}
			if (finish)																	//死亡或清关
			{
				score = 0; 
				stopbgm1();
				startbgm3();
				system("cls");
				gotoxy(22, 5);
				printf("Game Over!");
				gotoxy(24, 5);
				printf("按（1）键退出游戏，按其他任意键重玩");
				if (getch() == 49)                                  //1键的ASCII值为49
					break;
				system("cls"); 
			}
			else
			{
				system("cls");
				gotoxy(22, 5);
				printf("恭喜你通关了");
				gotoxy(24, 5);
				printf("按（1）键退出游戏，按其他任意键重玩");
				if (getch() == 49)
					break;
				system("cls");
			}
			
		}
		
	}

	return 0;
}
