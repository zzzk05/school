#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
#include <stack>
#include<windows.h>
using namespace std;

//�洢���δ������Ŀ
struct Data     
{
	string s;
	int tansw;
	int time;
	int th;
};


void gotoxy(int x, int y);   //λ�ú���
int color(int i);         //����������ɫ
void sjiemian();      //��ʼ����
int calculate(string s);    //������
string ques(char dj);    //������ʽ
int judge(string s, int i, struct Data data[], char dj);   //�����ж�
void qfor(int i, char dj);       //ѭ������
void sort(struct Data data[], int i);    //����












/*SetConsoleTextAttribute(hOut,BACKGROUND_RED |BACKGROUND_GREEN |BACKGROUND_BLUE |BACKGROUND_INTENSITY);
   ��ɫ����
   SetConsoleTextAttribute(hOut,BACKGROUND_GREEN |BACKGROUND_BLUE);
   ��ɫ����*/








/*���屳�����������*/
