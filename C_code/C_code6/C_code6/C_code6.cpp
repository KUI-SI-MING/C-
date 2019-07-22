#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 15

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

////////////////////////////////////////////////////////
//3.��������������������Ҷ���������������ͬ�ģ���Ϊ����ʱ����Ϊ������������ 1000 ���ڵ����л�������
int IsPrime(int n)
{
	int j = 0;
	if (n <= 1)
	{
		return 0;
	}
	if (n == 2)
		return 1;

	for (j = 2; j < n; j++)
	{
		if (n % j == 0)
			return 0;
		else if (n != j + 1)
			continue;
		else
			return 1;
	}
}

void PalindromePrimes()
{
	int i = 0;
	for (i = 10; i < 1000; i++)
	{
		//�����ж��Ƿ�Ϊ����
		if (IsPrime(i) == 1)
		{
			//�ж��Ǽ�λ��
			if (i / 100 == 0)
			{
				if (i / 10 == i % 10)
					cout << ' ' << i;
			}
			else
			{
				if (i / 100 == i % 10)
					cout << ' ' << i;
			}
			if (i % 5 == 0)
				cout << endl;
		}
	}
	cout << endl;
}

////////////////////////////////////////////////////////////////
//4,����һ�����ӵĳ�������һ���£���һ���¿ɳ��ɳ��ã���ô�����ÿ�Գ���ÿ���¶���һ��С�ã�һ��������С�ôӵڶ�����
//��Ϳ�ʼ�����ӣ����ʴ�һ�����ӿ�ʼ��ֳ���Ժ�ÿ���»��ж��ٶ�����
void Rabbit_Num()
{
	int month = 0;
	cout << "Please input Month: ";
	cin >> month;

	int r1 = 1;
	int r2 = 1;
	int r3 = 0;
	if (month == 1 || month == 2)
	{
		cout << "There is 1 Rabbits" << endl;
		return;
	}
	else
	{
		for (int i = 3; i <= month; i++)
		{
			r3 = r1 + r2;
			r1 = r2;
			r2 = r3;
		}
		cout << "There is " << r3 << " Rabbits" << endl;
	}

}

//////////////////////////////////////////////////////////////////
//5.����һ����Ϊ m��n �ף��� m �� n �У����� i �� j �е�Ԫ���� a(i,j)����Ҫ���þ���ת��Ϊ n��m �׵ľ���
//ʹ����Ԫ������ b(j,i)=a(i,j)
void Matrix_Translocation()
{
	int rows = 0;
	int cols = 0;
	vector<vector<int>> matrix;
	int new_matrix[MAXSIZE][MAXSIZE] = { 0 };

	cout << "Please input the number of the rows: ";
	cin >> rows;
	cout << endl << "Please input the number of the cols: ";
	cin >> cols;
	cout << endl;

	matrix.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Please input the element: ";
			int da = 0;
			cin >> da;
			matrix[i].push_back(da);
		}
	}

	cout << "The source matrx: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("\t%d", matrix[i][j]);
		}
		cout << endl;
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			new_matrix[j][i] = matrix[i][j];
		}
	}
	
	cout << "The new mawtrx: " << endl;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			printf("\t%d", new_matrix[i][j]);
		}
		cout << endl;
	}

}

////////////////////////////////////////////////////////////////////
//6.һֻ���Ӷ���� 10 �����ηֲ��Ķ���ĳһ�������ڵ�һ����û���ҵ����ӣ��͸�һ����������������ȥ�ң�
//Ҳû���ҵ����͸�������������������ȥ�ң��Ժ�ÿ�ζ��һ���� ȥ�����ӡ���������ȥ�����һֱ�Ҳ������ӣ�
//���ʣ����ӿ��ܶ����ĸ�����
void Chasing_Rabbits()
{
	bool pos[10] = { 0 };
	int hunter = 0;
	//�ж���Ҫȥ�Ķ����±�pos(i+1) = pos[i] + 1 + i
	for (int i = 0; i < 100; i++)
	{
		pos[hunter] = true;
		hunter++;
		hunter += i;
		hunter = hunter % 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!pos[i])
		{
			cout << "The Rabbit is in " << i + 1 << " Room" << endl;
		}
	}
}

/////////////////////////////////////////////////////////////
//7.�š����������Ҹ�������С����һ�죬���ҵľŸ�������һ��������ܣ��涨���������С���ܵ�һ�� 9 �֣��ܵڶ��� 8 �֣�
//�������ơ����������ʾ���ҵ��ܷ���ͬ������Щ����û��ͬʱ�����յ�ģ�Ҳû��һ�ҵ��������������ӻ�����������Ρ�
//��֪���һ��������ҵĺ��ӣ���ڶ����������ҵĺ��ӡ�������һ������˭�ҵĺ��ӣ�
int score[4][4];
void The_Slowest_Clr()
{
	int resu = 0;

	score[1][1] = 7;//�żҺ���������ߣ�7
	score[2][1] = 8;//���Һ���������ߣ�8
	score[3][1] = 9;//��Һ���������ߣ�9

	//ȷ��ÿ�Һ��ӵ�����
	for (int i = 4; i < 6; i++)
	{
		for (int j = 4; j < 7; j++)
		{
			for (int k = 4; i != j && k < 7; k++)
			{
				if (k != i && k != j && 15 - i - score[1][1] != 15 - j - score[2][1]
					&& 15 - i - score[1][1] != 15 - k - score[3][1]
					&& 15 - j - score[2][1] != 15 - k - score[3][1])
				{
					score[1][2] = i; score[1][3] = 15 - i - 7;
					score[2][2] = j; score[2][3] = 15 - j - 8;
					score[3][2] = k; score[3][3] = 15 - k - 9;
				}

			}
		}
	}
	
	//�ҵ����һ��
	for (int i = 1; i <= 3; i++, cout << endl)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << score[i][j];
			if (score[i][j] == 1)
			{
				resu = i;
			}
		}
	}

	if (resu == 1)
	{
		cout << "Is Mr.zhang" << endl;
	}
	else if (resu == 2)
	{
		cout << "Is Mr.wang" << endl;
	}
	else
	{
		cout << "Is Mr.li" << endl;
	}
}
int main()
{

	////1.�ж������ε�����
	//TypesOfJudgment();
	////2.����Ȼ����e
	//Evaluation();
	////3.��������
	//PalindromePrimes();
	////4.��������������
	//Rabbit_Num();
	////5.����ת��
	//Matrix_Translocation();
	////6.��׷��������
	//Chasing_Rabbits();
	////7.˭�Һ����ܵ�����
	The_Slowest_Clr();



	system("pause");
	return 0;
}

