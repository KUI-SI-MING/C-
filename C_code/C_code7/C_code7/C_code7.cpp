#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////
//1.���������������� n��ͨ���������������Ӧ�߶�Ϊ n �ĵ���������
void Trangle()
{
	int h = 0;
	cout << "Please input the highth of the trangle: ";
	cin >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= h - i; j++)
			putchar(' ');

		for (int j = 0; j <= 2 * i; j++)
		{
			putchar('*');
		}

		cout << endl;
	}
}
int main()
{
	////1.�������������
	Trangle();
	system("pause");
	return 0;
}