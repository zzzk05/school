#include"name.h"


//计算结果
int calculate(string s)
{
	stack<int> num;
	stack<char> op;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			temp += s[i];
		}
		if ((s[i] < '0' || s[i] > '9') && temp != "")
		{
			num.push(atoi(temp.c_str()));   //c_str将string转换为C语言中的字符串格式

			temp = "";
		}
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			op.push(s[i]);
		}
		if (s[i] == '*' || s[i] == '/')
		{
			if (!op.empty())
			{
				char lastop = op.top();
				if (lastop == '/')
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					num.push(firstnum*1.0 / secondnum);
					op.pop();
				}
			}
			op.push(s[i]);
		}
		if (s[i] == '+' || s[i] == '-')
		{
			if (i == 0 || s[i - 1] == '(' || s[i - 1] == '[' || s[i - 1] == '{')
			{
				num.push(0);
			}
			if (!op.empty())
			{
				char lastop = op.top();
				while (!op.empty() && (lastop == '*' || lastop == '/'))
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					if (lastop == '*')
						num.push(firstnum*secondnum);
					else if (lastop == '/')
						num.push(firstnum*1.0 / secondnum);
					op.pop();
					if (!op.empty())
						lastop = op.top();
				}
				if (lastop == '-')
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					num.push(firstnum - secondnum);
					op.pop();
				}
			}
			op.push(s[i]);
		}
		if (s[i] == ')')
		{
			if (!op.empty())
			{
				char lastop = op.top();
				while (!op.empty() && lastop != '(')
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					switch (lastop)
					{
					case '+':
						num.push(firstnum + secondnum);
						break;
					case '-':
						num.push(firstnum - secondnum);
						break;
					case '*':
						num.push(firstnum*secondnum);
						break;
					case '/':
						num.push(firstnum*1.0 / secondnum);
						break;
					}
					op.pop();
					if (!op.empty())
						lastop = op.top();
				}
				if (lastop == '(')
					op.pop();
			}
		}
		if (s[i] == ']')
		{
			if (!op.empty())
			{
				char lastop = op.top();
				while (!op.empty() && lastop != '[')
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					switch (lastop)
					{
					case '+':
						num.push(firstnum + secondnum);
						break;
					case '-':
						num.push(firstnum - secondnum);
						break;
					case '*':
						num.push(firstnum*secondnum);
						break;
					case '/':
						num.push(firstnum*1.0 / secondnum);
						break;
					}
					op.pop();
					if (!op.empty())
						lastop = op.top();
				}
				if (lastop == '[')
					op.pop();
			}
		}
		if (s[i] == '}')
		{
			if (!op.empty())
			{
				char lastop = op.top();
				while (!op.empty() && lastop != '{')
				{
					int secondnum = num.top();
					num.pop();
					int firstnum = num.top();
					num.pop();
					switch (lastop)
					{
					case '+':
						num.push(firstnum + secondnum);
						break;
					case '-':
						num.push(firstnum - secondnum);
						break;
					case '*':
						num.push(firstnum*secondnum);
						break;
					case '/':
						num.push(firstnum*1.0 / secondnum);
						break;
					}
					op.pop();
					if (!op.empty())
						lastop = op.top();
				}
				if (lastop == '{')
					op.pop();
			}
		}
	}
	if (temp != "")
		num.push(atoi(temp.c_str()));
	while (!op.empty())
	{
		char lastop = op.top();
		int secondnum = num.top();
		num.pop();
		int firstnum = num.top();
		num.pop();
		switch (lastop)
		{
		case '+':
			num.push(firstnum + secondnum);
			break;
		case '-':
			num.push(firstnum - secondnum);
			break;
		case '*':
			num.push(firstnum*secondnum);
			break;
		case '/':
			num.push(firstnum*1.0 / secondnum);
			break;
		}
		op.pop();
	}
	if (num.empty())
		return 0;
	int value = num.top();
	num.pop();
	return value;
}


// 产生算式
string ques(char dj)
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char opf[] = "+-*/",ss[30];
	int sz[4],fh[4];
	srand((unsigned)time(NULL));
	int a;
	int i = rand() % 2 + 3,j;
	for (a = 0; a < i; a++)
	{
		sz[a] = rand() % 10;                            //暂时改成10;
		if (dj == 'A')            //由等级选符号
		{
			j = rand() % 2;
		}
		else if (dj == 'B')
		{
			j = rand() % 2 + 2;
		}
		else if(dj == 'C')
		{
			j = rand() % 4;
		}
		else
		{
			system("cls");
			color(4);
			gotoxy(24, 7);
			printf("对不起，没有该等级。");
			gotoxy(0, 18);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			printf("按任意键返回难度选择界面");
			color(0);
			system("pause");
			system("cls");
			sjiemian();
		}
		if (a != i - 1)
		{
			fh[a] = opf[j];
		}
		else
			fh[a] = '=';
	}
	for (a = 0; a < i; a++)
	{
		if (fh[a] == '/')
		{
			if (sz[a + 1] == 0)
			{
				sz[a + 1] = 1;
			}
			else
			{
				sz[a] = sz[a] / sz[a + 1] * sz[a + 1];    //使算式中没有小数情况
			}
			
		}
	}
	for (a = 0; a < i; a++)
	{
		if (fh[a] == '/')
		{
			if (sz[a + 1] == 0)
			{
				sz[a + 1]++;
			}
		}
	}
	for (a = 0; a < i; a++)
	{
		if (a == 0)
		{
			sprintf(ss, "%d%c", sz[a], fh[a]);
		}
		else
		{
			sprintf(ss, "%s%d%c", ss, sz[a], fh[a]);
		}
	}
	return ss;
}


//判断正误
int judge(string s, int i, struct Data data[], char dj)
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	int tansw, yansw;
	int begin, end;
	tansw = calculate(s);
	if (dj == 'A')
		color(7);
	else if (dj == 'B')
		color(6);
	else color(5);
	printf("第%d题\n%s", i+1, s.c_str());
	begin = time(NULL);
	scanf("%d", &yansw);
	end = time(NULL);
	if (yansw == tansw)
	{
		gotoxy(29, 2);
		color(2);
		gotoxy(25, 4);
		printf("回答正确\n");
		gotoxy(25, 5);
		printf("本题用时%d秒\n", end - begin);
		data[i].s = s;
		data[i].time = end - begin;
		data[i].tansw = tansw;
		data[i].th = i+1;
		gotoxy(0, 18);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		printf("按任意键跳转到下一题");
		color(0);
		system("pause");
		system("cls");
		return 1;
	}
	else
	{
		color(4);
		gotoxy(25, 4);
		printf("回答错误\n");
		gotoxy(25, 5);
		printf("正确答案为：%d\n", tansw);
		return 0;
	}
}


// 循环出题
void qfor(int i, char dj)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	struct Data data[20];
	string s;        //算式字符串
	int a;         //正确错误返回值
	int j;
	int b = 1;
	for (j = 0; j < i; j++)
	{
		s = ques(dj);
		a = judge(s,j,data, dj);              //判断
		cout << endl;
		if (a == 0)
		{
			color(4);
			gotoxy(24, 9);
			printf("很遗憾！挑战失败！\n");
			gotoxy(0, 18);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			printf("按任意键返回难度选择界面\n");
			color(0);
			system("pause");
			system("cls");
			color(7);
			getchar();              //清理缓存
			sjiemian();
		}
	}
	if (a == 1)
	{
		system("cls");
		color(2);
		gotoxy(24, 0);
		printf("恭喜你！挑战成功！\n\n");
		sort(data, i);                //排序
		for (j = 0; j < i; j++)
		{
			printf("第%d题：%s%d\n", data[j].th, data[j].s.c_str(), data[j].tansw);
			printf("用时%d秒\n", data[j].time); cout << endl;
		}
		gotoxy(0, 18);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		printf("按任意键返回难度选择界面\n");
		color(0);
		system("pause");
		system("cls");
		sjiemian();
	}
}

//排序
void sort(struct Data data[], int i)
{
	int h,j;
	string tm;
	int sj;
	int da;
	int xh;              //排序用
	for (h = 0; h < i; h++)             //排序  输出用
	{
		for (j = 0; j < i - h - 1; j++)
		{
			if (data[j].time > data[j + 1].time)
			{
				//时间
				sj = data[j].time;
				data[j].time = data[j + 1].time;
				data[j + 1].time = sj;
				//答案
				da = data[j].tansw;
				data[j].tansw = data[j + 1].tansw;
				data[j + 1].tansw = da;
				//题号
				xh = data[j].th;
				data[j].th = data[j + 1].th;
				data[j + 1].th = xh;
				//题目
				tm = data[j].s;
				data[j].s = data[j + 1].s;
				data[j + 1].s = tm;
			}
		}
	}
}
