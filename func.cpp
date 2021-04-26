#include"name.h"


//������
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
			num.push(atoi(temp.c_str()));   //c_str��stringת��ΪC�����е��ַ�����ʽ

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


// ������ʽ
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
		sz[a] = rand() % 10;                            //��ʱ�ĳ�10;
		if (dj == 'A')            //�ɵȼ�ѡ����
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
			printf("�Բ���û�иõȼ���");
			gotoxy(0, 18);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			printf("������������Ѷ�ѡ�����");
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
				sz[a] = sz[a] / sz[a + 1] * sz[a + 1];    //ʹ��ʽ��û��С�����
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


//�ж�����
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
	printf("��%d��\n%s", i+1, s.c_str());
	begin = time(NULL);
	scanf("%d", &yansw);
	end = time(NULL);
	if (yansw == tansw)
	{
		gotoxy(29, 2);
		color(2);
		gotoxy(25, 4);
		printf("�ش���ȷ\n");
		gotoxy(25, 5);
		printf("������ʱ%d��\n", end - begin);
		data[i].s = s;
		data[i].time = end - begin;
		data[i].tansw = tansw;
		data[i].th = i+1;
		gotoxy(0, 18);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		printf("���������ת����һ��");
		color(0);
		system("pause");
		system("cls");
		return 1;
	}
	else
	{
		color(4);
		gotoxy(25, 4);
		printf("�ش����\n");
		gotoxy(25, 5);
		printf("��ȷ��Ϊ��%d\n", tansw);
		return 0;
	}
}


// ѭ������
void qfor(int i, char dj)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	struct Data data[20];
	string s;        //��ʽ�ַ���
	int a;         //��ȷ���󷵻�ֵ
	int j;
	int b = 1;
	for (j = 0; j < i; j++)
	{
		s = ques(dj);
		a = judge(s,j,data, dj);              //�ж�
		cout << endl;
		if (a == 0)
		{
			color(4);
			gotoxy(24, 9);
			printf("���ź�����սʧ�ܣ�\n");
			gotoxy(0, 18);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			printf("������������Ѷ�ѡ�����\n");
			color(0);
			system("pause");
			system("cls");
			color(7);
			getchar();              //������
			sjiemian();
		}
	}
	if (a == 1)
	{
		system("cls");
		color(2);
		gotoxy(24, 0);
		printf("��ϲ�㣡��ս�ɹ���\n\n");
		sort(data, i);                //����
		for (j = 0; j < i; j++)
		{
			printf("��%d�⣺%s%d\n", data[j].th, data[j].s.c_str(), data[j].tansw);
			printf("��ʱ%d��\n", data[j].time); cout << endl;
		}
		gotoxy(0, 18);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		printf("������������Ѷ�ѡ�����\n");
		color(0);
		system("pause");
		system("cls");
		sjiemian();
	}
}

//����
void sort(struct Data data[], int i)
{
	int h,j;
	string tm;
	int sj;
	int da;
	int xh;              //������
	for (h = 0; h < i; h++)             //����  �����
	{
		for (j = 0; j < i - h - 1; j++)
		{
			if (data[j].time > data[j + 1].time)
			{
				//ʱ��
				sj = data[j].time;
				data[j].time = data[j + 1].time;
				data[j + 1].time = sj;
				//��
				da = data[j].tansw;
				data[j].tansw = data[j + 1].tansw;
				data[j + 1].tansw = da;
				//���
				xh = data[j].th;
				data[j].th = data[j + 1].th;
				data[j + 1].th = xh;
				//��Ŀ
				tm = data[j].s;
				data[j].s = data[j + 1].s;
				data[j + 1].s = tm;
			}
		}
	}
}
