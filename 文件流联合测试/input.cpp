#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
int main(void)
{
	while (true)
	{
		ifstream fin("data.lw");
		if (fin)
		{
			cout << "�ļ���Ч,";
			string i;
			if(getline(fin,i))
				cout << "����" << i << endl;
			else
			{
				cout << "û�ж���" << endl;
			}
		}
		else
		{
			cout << "�ļ���Ч" << endl;
		}
		Sleep(100);
	}
	return 0;
}
