#include <iostream>
#include <assert.h>
#include <vector>
#define N 5
using namespace::std;

////////////////////////////////////////////////////////
//1.��ӡ����
void PrintPrime()
{
	int n1 = 0;
	int n2 = 0;

	cout << "Please input two numbers: ";
	cin >> n1 >> n2;

	int flag = 0;
	//���ж�n�Ƿ�����������n�ܷ񱻴�2��n-1�е���������
	//��n�ܴ�ʱ��Ч�ʵ���
	for (int i = n1; i <= n2; i++)
	{
		bool IsNoPrime = false;
		int data = i;
		for (int j = 2; j < data; j++)
		{
			if ((data % j) == 0)
			{
				IsNoPrime = true;
				break;
			}
		}
		if (!IsNoPrime)
		{
			cout << data << ' ';
			if (flag++ == 10)
			{
				cout << endl;
				flag = 0;
			}
		}
	}
	cout << endl << endl;
	//���й������£���n�ܱ�2~n-1�е������������������������бض���һ��С�ڵ��ڡ�n���ض�
	//��һ�����ڴ��ڵ��ڡ�n����ô�����С���㷶Χ
	flag = 0;
	for (int i = n1; i <= n2; i++)
	{
		bool IsNoPrime = false;
		int data = i;
		int k = (int)sqrt((double)data);//sqrt�Ĳ���������double

		for (int j = 2; j <= k; j++)
		{
			if ((data % j) == 0)
			{
				IsNoPrime = true;
				break;
			}
		}
		if (!IsNoPrime)
		{
			cout << data << ' ';
			if (flag++ == 10)
			{
				cout << endl;
				flag = 0;
			}
		}
	}
	cout << endl;
}

////////////////////////////////////////////////////////
//2.��ӡ�˷��ھ���
void PrintMultiplicationFormulatable()
{
	//����
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (j < i)
				cout << "       ";
			else
			{
				printf("%d*%d=%2d ", i, j, i * j);
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	//����
	for (int i = 1; i <= 9; i++)
	{
		for (int j = i; j <= 9; j++)
		{
			printf("%d*%d=%2d ", i, j, i * j);
		}
		cout << endl;
	}
	cout << endl << endl;

	//����
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j <= 9 - i; j++)
		{
			cout << "       ";
		}

		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", i, j, i * j);
		}
		cout << endl;
	}
	cout << endl << endl;

	//����
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", i, j, i * j);
		}
		cout << endl;
	}
	cout << endl << endl;

}

////////////////////////////////////////////////////////
//3.�ж�����
void IsLeapYear()
{
	int year = 0;
	cout << "Please input year:";
	cin >> year;
	assert(year > 0);

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		cout << "Is Leap Year!" << endl;
	}
	else
	{
		cout << "Is Not Leap Year!" << endl;
	}
}

////////////////////////////////////////////////////////
//4.��������
void Swap()
{
	int n1 = 0;
	int n2 = 0;

	cout << "Please input two numbers: ";
	cin >> n1 >> n2;

	cout << "n1: " << n1 << " " << "n2: " << n2 << endl;

	//�м������
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
	cout << "n1: " << n1 << " " << "n2: " << n2 << endl;

	//�Ӽ���--�����ֹ���ʱ���ھ�����
	n1 += n2;
	n2 = n1 - n2;
	n1 = n1 - n2;
	cout << "n1: " << n1 << " " << "n2: " << n2 << endl;

	//���
	n1 = n1 ^ n2;
	n2 = n2 ^ n1;
	n1 = n1 ^ n2;
	cout << "n1: " << n1 << " " << "n2: " << n2 << endl;

	//λ���㷨--�����ֹ���ʱ���ھ�����(2�ֽڴ洢��Χ��-32767-32767)
	n1 <<= 16;
	n1 += n2;
	n2 = n1 >> 16;
	n1 = n1 & 0xffff;
	cout << "n1: " << n1 << " " << "n2: " << n2 << endl;
}

////////////////////////////////////////////////////////
//5.���Լ��GCD
void FindGCD()
{
	unsigned int n1 = 0;
	unsigned int n2 = 0;

	cout << "Please input two numbers: ";
	cin >> n1 >> n2;

	////��ٷ�--Ч�ʵ���
	//vector<int> num;
	//for (int i = 1;i < 4294967296; i++)//32λ��unsigned int ��Χ0~4294967296
	//{
	//	if ((n1 % i == 0) && (n2 % i == 0))
	//	{
	//		num.push_back(i);
	//	}
	//}
	//cout << num[num.size() - 1] << endl;

	//���մӴ����������н�С��������С������С������1����˳�������һ����ͬʱ����
	//������������Ȼ��
	unsigned int max = n1;
	unsigned int min = n2;
	if (n1 < n2)
	{
		max = n2;
		min = n1;
	}

	for (int i = min; i > 0; i--)
	{
		if ((n1 % i == 0) && (n2 % i == 0))
		{
			cout << "The GCD Is: " << i << endl;
			break;
		}
	}

}

////////////////////////////////////////////////////////
//6.�������ݽ���
//������һ��ȿ��Խ��д���
//��������
void SwapNum(int* pa, int* pb)
{
	*pa ^= *pb;
	*pb ^= *pa;
	*pa ^= *pb;
}

void SwapElements()
{
	vector<int> arr1, arr2;

	cout << "Please Input Arr1 Elements:";
	int num = 0;
	while (cin >> num)
	{
		arr1.push_back(num);
		if (arr1.size() > N - 1)
			break;

		cout << "Please Input Arr1 Elements:";
	}
	cout << endl << endl;

	cout << "Please Input Arr2 Elements:";
	while (cin >> num)
	{
		arr2.push_back(num);
		if (arr2.size() > N - 1)
			break;

		cout << "Please Input Arr2 Elements:";
	}
	cout << endl << endl;

	cout << "The Arr1 Is: ";
	for (int i = 0; i < arr1.size(); i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl << endl;
	cout << "The Arr2 Is:";
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << ' ';
	}
	cout << endl << endl;

	for (int i = 0; i < arr1.size(); i++)
	{
		SwapNum(&arr1[i], &arr2[i]);
	}
	cout << endl << endl;

	cout << "The Arr1 Is: ";
	for (int i = 0; i < arr1.size(); i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl << endl;
	cout << "The Arr2 Is: ";
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << ' ';
	}
	cout << endl << endl;
}

////////////////////////////////////////////////////////
//7.����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
void SumofFraction()
{
	double sum = 0.0;
	for (int i = 1; i <= 100; i++)
	{
		sum += pow(-1, i + 1) / i;
	}

	cout << "The Sum of '1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100' Is: " << sum << endl;
}


////////////////////////////////////////////////////////
//8.1~100 �����������г��ֶ��ٴ�����9
void NineNumber()
{

	int cou = 0;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		int tmp = 1;
		int nu = i;
		while (nu > 0)
		{
			tmp = nu % 10;
			if ((tmp / 9) == 1)
				cou++;
			nu = nu / 10;
		}
	}
	cout << "The number of 9 is: " << cou<< endl;//90
}

int main()
{
	////1.��ӡ����
	//PrintPrime();
	////2.��ӡ�˷��ھ���
	//PrintMultiplicationFormulatable();
	////3.�ж�����
	//IsLeapYear();
	////4.��������
	//Swap();
	////5.���Լ��GCD
	//FindGCD();
	////6.�������ݽ���
	//SwapElements();
	////7.�������
	//SumofFraction();
	////8.��������
	NineNumber();


	system("pause");
	return 0;
}





