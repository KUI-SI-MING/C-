#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
#define N 100

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

////////////////////////////////////////////////////
//2.���Ϊ 1��2��3������n �� n ����Χ��һȦ����ѡһ�������� m ��Ϊ��������ֵ��
//�ӵ�һ���˿�ʼ��˳ʱ�뷽������������ m ʱֹͣ������Ϊ m ���˳��С�
//�ӳ����˵�˳ʱ�뷽�����һ���˿�ʼ�ִ� 1 ���±����������ȥ��ֱ�������˶�ȫ������Ϊֹ
void _joseph(int a[], int n, int m)
{
	int k = 0;
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		j = 1;
		while (j < m)
		{
			while (a[k] == 0)
				k = (k + 1) % n;
			j++;
			k = (k + 1) % n;
		}

		while (a[k] == 0)
			k = (k + 1) % n;
		cout << a[k] << ' ';
		a[k] = 0;
	}
}

void Joseph()
{
	int da[N] = { 0 };
	int num = 0;
	int count = 0;
	cout << "Please input num & count: ";
	cin >> num >> count;

	for (int i = 0; i < num; i++)
	{
		da[i] = i + 1;
	}

	cout << endl << "The output is " << endl;
	_joseph(da, num, count);
	cout << endl;

}
int main()
{
	////1.�������������
	//Trangle();
	////2.Լɪ��
	Joseph();

	system("pause");
	return 0;
}