#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main(void)
{
	while (true)
	{
		ifstream fin("data.lw");
		if (fin)
		{
			cout << "文件有效,";
			int i;
			if(fin >> i)
				cout << "读到" << i << endl;
			else
			{
				cout << "没有读到" << endl;
			}
		}
		else
		{
			cout << "文件无效" << endl;
		}
		Sleep(100);
	}
	return 0;
}