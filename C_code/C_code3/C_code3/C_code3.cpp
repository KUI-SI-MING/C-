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

int main()
{
	////1.ƽ��ֵ
	//AverageValue();
	////2.������ֻ����һ�ε�����
	FindNumsAppearOnce();

	system("pause");
	return 0;
}