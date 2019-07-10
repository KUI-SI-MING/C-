#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/////////////////////////////////////////////////////////////////
//1.������������ε��������ж������ε����ͣ�����������������
void TypesOfJudgment()
{
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	float sum = 0;
	float area = 0;

	cout << "Please input Three sides: ";
	cin >> x1 >> x2 >> x3;

	//�ж��Ƿ񹹳�������
	if ((x1 + x2) > x3 && (x2 + x3) > x1 && (x1 + x3) > x2)
	{
		sum = (x1 + x2 + x3) / 2;
		area = (float)sqrt(sum * (sum - x1) * (sum - x2) * (sum - x3));
		cout << "The area of Triangle is: " << area << endl;
		if (x1 == x2 && x1 == x3)
		{
			cout << "Equilateral triangle!" << endl;
		}
		else if (x1 == x2 || x1 == x3 || x2 == x3)
		{
			cout << "Isosceles triangle!" << endl;
		}
		else if(x1 * x1 + x2 * x2 == x3 * x3 || x3 * x3 + x2 * x2 == x1 * x1 || x1 * x1 + x3 * x3 == x2 * x2)
		{
			cout << "Right triangle!" << endl;
		}
		else
		{
			cout << "Common triangle!" << endl;
		}
	}
	else
	{
		cout << "Is not a triangle!" << endl;
	}
}

////////////////////////////////////////////////////////////////////////////
//2.��Ȼ���� e=2.718281828����e �ļ��㹫ʽ���£�e = 1 + 1 / 1!+ 1 / 2!+ 1 / 3!+ ��Ҫ�����һ���ֵС��
//10^10 ʱ����
void Evaluation()
{
	float e = 1.0;
	float n = 1.0;
	int i = 1;

	//ѭ����������
	while (1 / n > 1e-10)
	{
		e += 1 / n;
		i++;
		n = i * n;
	}

	cout << "\n" << "The value of e is: " << e << endl;
}

int main()
{

	////1.�ж������ε�����
	//TypesOfJudgment();
	////2.����Ȼ����e
	Evaluation();

	system("pause");
	return 0;
}