#include "snake.cpp"

//ת�ýṹ����
extern  struct Food food;  //extern���ڱ�������������ǰ������˵�����˱���/�������ڱ𴦶���ģ�Ҫ�ڴ˴����á� 
extern  struct Snake snake;

//������
int main()
{
	ret = menu();
	if (ret == 1)
	{
		while (finish)
		{
			initMap();																	//��ʼ����ͼ 
			while (TRUE)
			{
				stopbgm3();
				startbgm1();
				updataFood();														//����ʳ�� 
				getSpeed(); 													//�ٶ� 
				moveSnake();														//�ƶ��� 
				Sleep(snake.speed);									//ʹ��sleep()��������������,�����ߵ��ٶ�,��<windows.h>�� 
				printFont(FONT_WINDOW_STARTX, FONT_WINDOW_STARTY, snake.speed);		//�ұߴ��� 
				if (!(isAlive()))
						break;
					
			}
			if (finish)																	//���������
			{
				score = 0; 
				stopbgm1();
				startbgm3();
				system("cls");
				gotoxy(22, 5);
				printf("Game Over!");
				gotoxy(24, 5);
				printf("����1�����˳���Ϸ�����������������");
				if (getch() == 49)                                  //1����ASCIIֵΪ49
					break;
				system("cls"); 
			}
			else
			{
				system("cls");
				gotoxy(22, 5);
				printf("��ϲ��ͨ����");
				gotoxy(24, 5);
				printf("����1�����˳���Ϸ�����������������");
				if (getch() == 49)
					break;
				system("cls");
			}
			
		}
		
	}

	return 0;
}
