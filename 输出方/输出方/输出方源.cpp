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
			cout << "�ļ���Ч,";
			fout << ++i;
			cout << "д��" << i << endl;
		}
		else
		{
			cout << "�ļ���Ч" << endl;
		}
		fout.close();
		Sleep(100);
	}
	return 0;
}