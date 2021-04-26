#include"name.h"


//位置函数
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//字体颜色   1深蓝 9浅蓝 3淡蓝 11淡淡蓝 2绿 4红 5紫 13浅紫 7白 6黄
int color(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	return 0;
}

//起始界面
void sjiemian()
{
	int a;   //是否返回标记

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);         


	gotoxy(29, 2);
	color(1);
	printf("越算越开心!");
	gotoxy(15, 5);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("难度：");
	gotoxy(31, 5);
	color(7);
	printf("A.低级");
	gotoxy(31, 7);
	color(6);
	printf("B.中级");
	gotoxy(31, 9);
	color(5);
	printf("C.高级");
	gotoxy(12, 11);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("请选择难度等级：");
	gotoxy(34, 11);
	char BZ;
	scanf("%c", &BZ);
	setbuf(stdin, NULL);
	color(7);
	system("cls");
	qfor(20, BZ);
}