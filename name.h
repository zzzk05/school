#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
#include <stack>
#include<windows.h>
using namespace std;

//存储本次答完的题目
struct Data     
{
	string s;
	int tansw;
	int time;
	int th;
};


void gotoxy(int x, int y);   //位置函数
int color(int i);         //设置字体颜色
void sjiemian();      //起始界面
int calculate(string s);    //计算结果
string ques(char dj);    //产生算式
int judge(string s, int i, struct Data data[], char dj);   //进行判断
void qfor(int i, char dj);       //循环出题
void sort(struct Data data[], int i);    //排序












/*SetConsoleTextAttribute(hOut,BACKGROUND_RED |BACKGROUND_GREEN |BACKGROUND_BLUE |BACKGROUND_INTENSITY);
   白色背景
   SetConsoleTextAttribute(hOut,BACKGROUND_GREEN |BACKGROUND_BLUE);
   蓝色背景*/








/*字体背景函数不理解*/
