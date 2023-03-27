#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

double write_double()
{
	while (bool inp = 1)
	{
		int i;
		vector<char> char_array;  // ������ ������� ����� ������� ������� �������� � ����������
		double a = 0;
		char_array.clear();  // �������� ������� ���� ����� ������� �������� ��������
		for (i = 0; i != -1; i++)  // ���� �� ����� ���� � ������
		{
			char sim = _getch();  // ���������� ������� � ����������
			if (sim != '\r')
			{
				if (sim == '\b' && char_array.size() != 0)
				{
					cout << sim << ' ' << sim;
					char_array.pop_back();
				}
				if (sim == '.' || sim <= '9' && sim >= '0') // ������� �������
				{
					cout << sim;
					char_array.push_back(sim); // ������ �������� � ������
				}
			}
			else
			{
				cout << endl;
				i = -2;
			}
		}
		string number(char_array.begin(), char_array.end()); // ������ ��������� �������� �� �������
		if (number != "0")
		{
			int p = number.find_first_not_of('0', 0); // ���������� ������� ������� ��������� �� 0
			if (p != 1)
			{
				number = number.erase(0, p);
			}
		}
		int s = size(number);  // ���������� s ��������� �������� ����� ������ number
		if (number == "" || number[0] == '.' || s > 9 || number[s-1] == '.') // �������� ������
		{
			cout << "Error. Write again: ";
			inp = 1;
		}
		else
		{
			a = stod(number); // ���������� � ��������� ����� ������
			inp = 0;
			return a;
		}
	}
}

int main()
{
	bool begin = true;
	while (begin)
	{
		cout << "Input the number of pipes = ";
		bool integer = 1;
		double pipes = 0;
			while (integer == 1)
			{
				pipes = 0;
				pipes = write_double();
				int check = pipes;
				if (pipes / check > 1)
				{
					cout << endl << "Error. Input integer number = ";
					integer = 1;
				}
				else
					integer = 0;
			}
		vector<double> time_filling;
		for (int i = 0; i < pipes; i++)
		{
			cout << "Input filling time for the pipe #" << i + 1 << " = ";
			double time = write_double();
			time_filling.push_back(time);
		}
		double speed = 0;
		for (int j = 0; j != size(time_filling); j++)
		{
			speed += 1 / time_filling[j];
		}
		double fin_time = 1 / speed;
		cout << fin_time << endl << "Continue? (Y/N) ";
		char end = 0;
		while (end != 'y' && end != 'n' && end != 'Y' && end != 'N') // �����
		{
			end = _getch();
		}
		cout << end << endl;
		begin = (end == 'y' || end == 'Y');
	}
}