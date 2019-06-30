#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;

////////////////////////////////////////////////////////
//1.用希尔排序法对一组数据由小到大进行排序
void Hill_Sort()
{
	vector<int> num;
	int n = 0;
	int count = 0;
	num.push_back(0);

	cout << "Please input the count of number: ";
	cin >> count;

	int tmp = count;
	cout << "Please input a number: ";
	while (cin >> n)
	{
		tmp--;
		num.push_back(n);

		if (tmp == 0)
			break;
		cout << "Please input a number: ";
	}

	int i = 0;
	int j = 0;
	int d = count / 2;
	while (d >= 1)
	{
		for (i = d + 1; i <= count; i++)
		{
			num[0] = num[i];
			j = i - d;
			while ((j > 0) && (num[0] < num[j]))
			{
				num[j + d] = num[j];
				j = j - d;
			}
			num[j + d] = num[0];
		}
		d = d / 2;
	}

	cout << "The new number is: ";
	for (i = 1; i <= count; i++)
	{
		cout << ' ' << num[i];
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////
//2.冒泡排序
void Bubble_Sort()
{
	vector<int> num;
	int n = 0;
	int count = 0;
	num.push_back(0);

	cout << "Please input the count of number: ";
	cin >> count;

	int tmp = count;
	cout << "Please input a number: ";
	while (cin >> n)
	{
		tmp--;
		num.push_back(n);

		if (tmp == 0)
			break;
		cout << "Please input a number: ";
	}

	int i = 0;
	int j = 0;
	for(i = 1;i < num.size() - 1;i++)//比较趟数
		for (j = 1; j < num.size() - i; j++)//每一趟比较次数
		{
			if (num[j] > num[j + 1])
				swap(num[j], num[j + 1]);
		}

	cout << "The new number is: ";
	for (i = 1; i <= count; i++)
	{
		cout << ' ' << num[i];
	}
	cout << endl;
}

int main()
{
	////1.希尔排序
	//Hill_Sort();
	////2.冒泡排序
	Bubble_Sort();


	system("pause");
	return 0;
}