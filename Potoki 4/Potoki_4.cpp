#define _CRT_SECURE_NO_WARNINGS
#include<iostream>//istream ostream
#include<fstream>
#include<Windows.h>
#include<string.h>
using namespace std;
void RussianMessage(const char* message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	cout << rmessage;
}
int RussianMenu()
{
	RussianMessage("\n�������  1 ��� ���������� ����� ��������� � ����\n");
	RussianMessage("\n������� 2 ��� ������ ���� �������� �� �����\n");
	RussianMessage("\n������� 3 ��� ������\n");
	int choice;
	cin >> choice;
	return choice;
}
class Man
{
	int age;
	char* name;
	char* surname;
	int count;

public:
	Man()
	{
		name = 0;
		surname = 0;
		age = 0;
	}
	Man(const char* n, const char* s, int a)
	{
		name = new char[strlen(n) + 1];
		if (!name)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(name, n);
		surname = new char[strlen(s) + 1];
		if (!surname)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(surname, s);
		age = a;
	}

	~Man()
	{
		delete[] name;
		delete[] surname;
	}
	void Put()
	{
		char temp[1024];
		RussianMessage("\n������� ���:\n");
		cin >> temp;
		if (name)
			delete[] name;
		name = new char[strlen(temp) + 1];
		if (!name)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(name, temp);
		RussianMessage("\n������� �������:\n");
		cin >> temp;
		if (surname)
			delete[] surname;
		surname = new char[strlen(temp) + 1];
		if (!surname)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(surname, temp);
		RussianMessage("\n������� �������\n");
		cin >> age;
	}
	void Show()
	{
		RussianMessage("\n���\n");
		cout << name;
		RussianMessage("\n�������\n");
		cout << surname;
		RussianMessage("\n�������\n");
		cout << age << endl;
	}
	void SaveToFile()
	{
		ofstream f("D:\\men.txt", ios::out | ios::binary | ios::app);
		if (!f) {
			RussianMessage("���� �� �������� ��� ������!!!");
			exit(1);
		}
		f << name;
		f << "\n";
		f << surname;
		f << "\n";
		f << age;
		f.close();
	}
	void  ShowFromFile()
	{
		ifstream f("D:\\men.txt", ios::out | ios::binary);
		if (!f) {
			RussianMessage("���� �� �������� ��� ������!!!");
			exit(1);
		}
		
		while (!f.eof())
		{
			char buff[50];
			int a;
			f >> buff;
			RussianMessage("\n���\n");
			cout << buff;
			f >> buff;
			RussianMessage("\n�������\n");
			cout << buff;
			RussianMessage("\n�������\n");
			f >> a;
			cout << a << endl;

		}
	}
};
void main()
{
	Man* a;
	a = new Man;
	do
	{
		switch (RussianMenu()) {
		case 1:
			a->Put();
			a->SaveToFile();
			break;
		case 2:
			a->ShowFromFile();
			break;
		case 3:
			RussianMessage("�� ��������\n");
			return;
		default:
			RussianMessage("�������� ����\n");
		}
	} while (1);
}