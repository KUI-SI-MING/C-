#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
#define N 3

////////////////////////////////////////////////////
//1,����������ƽ��ֵ
int Plus(int d1, int d2)
{
	while (d2 != 0)
	{
		int orbit = d1 ^ d2;
		d2 = d1 & d2;
		d1 = orbit;
		d2 <<= 1;//��λ
	}

	return d1;
}

void AverageValue()
{
	int n1 = 0;
	int n2 = 0;

	cout << "Please input 2 numbers: ";
	cin >> n1 >> n2;

	int ave;
	//�٣�n1 + n2�� / 2
	//���Ƴ� 2
	ave = (n1 + n2) >> 1;//�����Ϻͣ�n1 + n2�� / 2��δ������
	cout << "The average of " << n1 << " and " << n2 << " is " << ave << endl;
	
	//�ڿ���n1��n2�����������
	ave = n1 - (n1 - n2) / 2;
	cout << "The average of " << n1 << " and " << n2 << " is " << ave << endl;
	 
	//������λ��������м���
	//n1��Ϊ����֮��
	ave = Plus(((n1 ^ n2) >> 1) , n1 & n2);//(����λ��1 + 0��0 + 1��ƽ��ֵ�� 1 + 1��ƽ��ֵ)
	cout << "The average of " << n1 << " and " << n2 << " is " << ave << endl;
}

////////////////////////////////////////////////////
//2.һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ��������
void FindNumsAppearOnce()
{
	int size;
	cout << "Please input the size if the array: ";
	cin >> size;

	vector<int> arr;
	for (int i = 0; i < size; i++)
	{
		int d = 0;
		cout << "Please input the elements if the array: ";
		cin >> d;

		arr.push_back(d);
	}

	int res = arr[0];
	for (int i = 1; i < size; i++)
	{
		res ^= arr[i];
	}
	cout << "The number is: " << res << endl;
}


////////////////////////////////////////////////////
//3.��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ��
//����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ�
void RotatingArray()
{
	string str;

	cout << "Please input Character array: ";
	getline(cin, str);

	int start = 0;
	int end = str.size() - 1;

	//����ǰ������
	while (start < end)
	{
		swap(str[start], str[end]);
		start++;
		end--;
	}

	int wordsize = 0;
	//��ÿ����������
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] != ' ' && str[i] != '\0')//�������һ������
		{
			wordsize++;
			continue;
		}

		if (wordsize == 1)
		{
			wordsize = 0;
			continue;
		}

		start = i - wordsize;
		end = i - 1;
		while (start < end)
		{
			swap(str[start], str[end]);
			start++;
			end--;
		}
		wordsize = 0;
	}

	cout << "The new Character array is: " << str << endl;

}

////////////////////////////////////////////////////
//4.����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ��
//���֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò���
void reOrderArray()
{
	int size;
	cout << "Please input the size if the array: ";
	cin >> size;

	vector<int> array;
	for (int i = 0; i < size; i++)
	{
		int d = 0;
		cout << "Please input the elements if the array: ";
		cin >> d;

		array.push_back(d);
	}

	int length = array.size() - 1;
	int end = length;

	while (end >= 0)
	{
		if (array[end] % 2 == 1)
		{
			for (int i = end - 1; i >= 0; i--)
			{
				int tmp = 0;
				//�����ý������������λ�ã����Բ�ȡƽ�Ƶķ�ʽ
				if (array[i] % 2 == 0)
				{
					tmp = array[i];
					for (int j = i; j < end; j++)
					{
						array[j] = array[j + 1];
					}
					array[end] = tmp;
					break;
				}
			}
		}
		end--;
	}

	cout << "The new array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << ' ' << array[i] << ' ';
	}
	cout << endl;

}

////////////////////////////////////////////////////
//5.���Ͼ���
//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
//�մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ�
//���и�����
bool _Find(int target, vector<vector<int> >& array)
{
	int rows = array.size();
	int cols = array[0].size();

	if (array.size() > 0)
	{
		int i = 0;
		int j = cols - 1;
		while ((i < rows) && (j >= 0))
		{
			if (array[i][j] == target)
			{
				return true;
			}
			else if (array[i][j] < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	return false;
}

void Find()
{
	vector<vector<int> > array(N, vector<int> (N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int da = 0;
			cout << "Please input array's elements: ";
			cin >> da;
			array[i][j] = da;
		}
	}

	int target = 0;
	cout << "Please input your find number: ";
	cin >> target;
	cout << endl;

	if (_Find(target, array))
	{
		cout << "Find success!" << endl;
	}
	else
	{
		cout << "Find failed!" << endl;
	}
}

int main()
{
	////1.ƽ��ֵ
	//AverageValue();
	////2.������ֻ����һ�ε�����
	//FindNumsAppearOnce();
	/////3.������ת
	//RotatingArray();
	////4.��������˳��ʹ����λ��ż��ǰ��
	//reOrderArray();
	////5.���Ͼ���
	Find();


	system("pause");
	return 0;
}