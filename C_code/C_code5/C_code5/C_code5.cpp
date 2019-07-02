#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;

////////////////////////////////////////////////////////
//1.��ϣ�����򷨶�һ��������С�����������
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
//2.ð������
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
	for(i = 1;i < num.size() - 1;i++)//�Ƚ�����
		for (j = 1; j < num.size() - i; j++)//ÿһ�˱Ƚϴ���
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

/////////////////////////////////////////////////////////////////
//3.���������ǰ�һ����¼���뵽����������������У�ʹ���������ڲ���ü�¼����Ȼ���򡣲��������нϼ򵥵��ַ�����
//ֱ�Ӳ������������λ�õ�ȷ�������ǽ�������ļ�¼���������еĸ���¼�����������αȽ���ؼ���ֵ�Ĵ�С��
//��ʵ��Ҫ��ʹ��ֱ�Ӳ������򷨽�������С�����������
void Insert_Sort()
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
	for (i = 2; i <= num.size() - 1; i++)
	{
		num[0] = num[i];
		j = i - 1;
		while (num[0] < num[j])
		{
			num[j + 1] = num[j];
			j--;
		}

		num[j + 1] = num[0];
	}

	cout << "The new number is: ";
	for (i = 1; i <= count; i++)
	{
		cout << ' ' << num[i];
	}
	cout << endl;

}

/////////////////////////////////////////////////////////////////
//4.�ÿ������򷨶�һ��������С�����������
int quick_sort(vector<int>& n, int start, int end)
{
	int i = start;	
	int j = end;
	n[0] = n[start];

	while (i < j)
	{
		while (i < j && n[0] < n[j])
			j--;
		if (i < j)
		{
			n[i] = n[j];
			i++;
		}

		while (i < j && n[i] <= n[0])
			i++;
		if (i < j)
		{
			n[j] = n[i];
			j--;
		}

		n[i] = n[0];
		if (start < i)
			quick_sort(n, start, j - 1);
		if (i < end)
			quick_sort(n, j + 1, end);

		}

	return 0;
}

void Quick_Sort()
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

	quick_sort(num, 1, num.size() - 1);

	
	cout << "The new number is: ";
	for (int i = 1; i <= count; i++)
	{
		cout << ' ' << num[i];
	}
	cout << endl;
}

int main()
{
	////1.ϣ������
	//Hill_Sort();
	////2.ð������
	//Bubble_Sort();
	////3.��������
	//Insert_Sort();
	////4.��������
	Quick_Sort();



	system("pause");
	return 0;
}