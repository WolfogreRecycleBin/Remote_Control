#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main(void)
{
	int i = 0;
	while (true)
	{
		ofstream fout("data.lw");
		if (fout)
		{
			cout << "文件有效,";
			fout << ++i;
			cout << "写入" << i << endl;
		}
		else
		{
			cout << "文件无效" << endl;
		}
		fout.close();
		Sleep(100);
	}
	return 0;
}