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
int main()
{
	////1.ƽ��ֵ
	AverageValue();

	system("pause");
	return 0;
}