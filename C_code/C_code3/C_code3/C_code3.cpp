#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

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
int main()
{
	////1.ƽ��ֵ
	//AverageValue();
	////2.������ֻ����һ�ε�����
	//FindNumsAppearOnce();
	/////3.������ת
	RotatingArray();

	system("pause");
	return 0;
}