/* Дано літерний рядок, який містить послідовність символів s0, …, sn, ….Відомо, що
серед цих символів є по крайній мірі чотири крапки.
1. Знайти число і таке, що sі – четверта від кінця послідовності крапка.
2. Замінити кожну крапку парою зірочок “ * *" */
#include <iostream>
#include <string>
using namespace std;

int findIndex(char* str, char x)
{
	int index = -1;
	int m = 0;
	for (int i = (strlen(str) - 1); i >= 0; i--)
	{
		if (str[i] == x)
			m++;
		if (m == 4)
		{
			index = i;
			break;
		}
	
	}
	return index;
}

char* change(char* str)
{
	char* tmp = new char[strlen(str)];
	char* t = tmp;
	tmp[0] = '\0';
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '.')
		{
			strcat_s(t, 101, "**");
			t += 2;
			i += 1;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}

	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, 101, tmp);
	return tmp;
}

int main()
{
	 
	char str[101];
	char x = '.';

	cout << "Enter string:" << endl;
	cin >> str;

	int index = findIndex(str, x);
	if (index == -1)
	{
		cout << "Character not found" << endl;;
	}
	else
	{
		cout << "Last index of the dot is " << index << endl;;
	}
	
	cout << "Replacing dots with two asterisks: " << change(str);
	return 0;
}