#include"name.h"


//λ�ú���
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//������ɫ   1���� 9ǳ�� 3���� 11������ 2�� 4�� 5�� 13ǳ�� 7�� 6��
int color(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	return 0;
}

//��ʼ����
void sjiemian()
{
	int a;   //�Ƿ񷵻ر��

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);         


	gotoxy(29, 2);
	color(1);
	printf("Խ��Խ����!");
	gotoxy(15, 5);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("�Ѷȣ�");
	gotoxy(31, 5);
	color(7);
	printf("A.�ͼ�");
	gotoxy(31, 7);
	color(6);
	printf("B.�м�");
	gotoxy(31, 9);
	color(5);
	printf("C.�߼�");
	gotoxy(12, 11);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("��ѡ���Ѷȵȼ���");
	gotoxy(34, 11);
	char BZ;
	scanf("%c", &BZ);
	setbuf(stdin, NULL);
	color(7);
	system("cls");
	qfor(20, BZ);
}