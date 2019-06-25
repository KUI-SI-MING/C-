#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#define N 100
#define M 100
#define YEAR 2011

using namespace std;

/////////////////////////////////////////////////////////
//1.��дһ������reverse_string(char * string)���ݹ�ʵ�֣� ʵ�֣��������ַ����е��ַ��������С�
void Reverse_string(char* string)
{
	static char arr[N] = { 0 };//��¼�ַ���
	static char* p = arr;
	static char* q = arr;

	if (*string != '\0')
	{
		*q = *string;
		q++;
		
		Reverse_string(string + 1);
		*string = *p;//��ת
		p++;
	}


}

void ReverseString()
{
	char str[N] = { 0 };

	cout << "Please input a string�� ";
	gets_s(str);

	Reverse_string(str);

	cout << "The new str is: " << str << endl;
}

///////////////////////////////////////////////////////////////
//2.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ�
int _RMyStrlen(const char* str)
{ 
	if (*str == '\0')
		return 0;

	return 1 + _RMyStrlen(str + 1);

}

//�ǵݹ�
int _NotRMyStrlen(string& str)
{
	int count = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}

	return count;
}

void MyStrlen()
{
	string str;
	cout << "Please input a string: ";
	getline(cin , str);

	const char* ps = str.data();
	int size = _RMyStrlen(ps);
	cout << "The size of " << str << " is: " << size << endl;

	size = _NotRMyStrlen(str);
	cout << "The size of " << str << " is: " << size << endl;
}

///////////////////////////////////////////////////////
//3.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
long _RFactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * _RFactorial(n - 1);
}

//�ǵݹ�
long _NotRFactorial(int n)
{
	long  res = 1;
	int tmp = n;
	while (tmp)
	{
		res *= tmp;
		tmp--;
	}

	return res;
}
void Factorial()
{
	int  n = 0;
	cout << "Please input a number: ";
	cin >> n;

	long res = _RFactorial(n);
	cout << "The Factorial of " << n << " is: " << res << endl;

	res = _NotRFactorial(n);
	cout << "The Factorial of " << n << " is: " << res << endl;

}

///////////////////////////////////////////////////////////
//4.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void _RDecomposition_Integer(int n)
{
	if (n > 9)
		_RDecomposition_Integer(n / 10);
		
	cout << ' ' << n % 10;

}

void Decomposition_Integer()
{
	int n = 0;
	cout << "Please input a number: ";
	cin >> n;

	cout << "The elements of the number is: ";
	_RDecomposition_Integer(n);
	cout << endl;
}

///////////////////////////////////////////////////////////////
//5.�ÿɱ������ʵ�ֺ���������������ƽ��ֵ
int CalculateAverage(int n, ...)
{
	va_list arg;
	int i = 0;
	int sum = 0;
	__crt_va_start (arg, n);
	for (i = 0; i < n; i++)
	{
		sum += __crt_va_arg(arg, int);
	}
	__crt_va_end(arg);
	return sum / n;
}

void VariableParameters()
{
	int n1 = 0, n2 = 0, n3 = 0;
	cout << "Please input three number: ";
	cin >> n1 >> n2 >> n3;

	int ave1 = CalculateAverage(2, n1, n2);
	int ave2 = CalculateAverage(3, n1, n2, n3);
	cout << "The average of " << n1 << ' ' << n2 << " is: " << ave1 << endl;
	cout << "The average of " << n1 << ' ' << n2 << ' ' << n3 <<  " is: " << ave2 << endl;

}

//////////////////////////////////////////////////////////////////
//6..ʹ�ÿɱ������ʵ�ֺ������������������ֵ
int MaxValue(int n, ...)
{
	va_list arg;
	int i = 0;
	int max = 0;
	__crt_va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		int tmp = __crt_va_arg(arg, int);

		if (max < tmp)
			max = tmp;
	}
	__crt_va_end(arg);
	return max;
}
void VariableParameters_Max()
{

	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
	cout << "Please input five number: ";
	cin >> n1 >> n2 >> n3 >> n4 >> n5;

	int max1 = MaxValue(3, n1, n2, n3);
	cout << "The Max of " << n1 << ' ' << n2 << ' ' << n3 <<  " is: " << max1 << endl;

	int max2 = MaxValue(5,n1, n2, n3, n4, n5);
	cout << "The Max of " << n1 << ' ' << n2 << ' ' << n3  << ' ' << n4 \
		<< ' ' << n5 << " is: " << max2 << endl;

}

///////////////////////////////////////////////////////////////
//7.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ?
void Dynamic_planning()
{
	int money = 0;
	cout << "Please input a number: ";
	cin >> money;

	int sum = money;//��ƿ��
	int empty = money;//��ƿ��
	while (empty >= 2)
	{
		sum += empty / 2;
		empty = empty / 2 + empty % 2;//����ƿ������ƿʱ��������ʣ��һ��ƿ���´λ�
	}

	cout << "There is " << sum << " bottles!" << endl;
}

////////////////////////////////////////////////////////////
//8.���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬������񫣬�ֶ����һ�����ڶ���
//�����ֽ���һ��ʣ�µ����ӳԵ�һ�룬�ж����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ��
//���� 10 ���������ٳ�ʱ������ֻʣ��һ�������ˡ���д��������ӵ�һ��ժ�˶��ٸ�����
void EatPeach()
{
	int day = 0;
	cout << "Please input days: ";
	cin >> day;

	int i = day - 1;
	int current = 1;
	int front = 0;
	while (i > 0)
	{
		front = (current + 1) * 2;
		current = front;
		i--;
	}

	cout << "The paches number is: " << front << endl;
}

//////////////////////////////////////////////////////
//9.�й��Ŵ���ѧ�����������ġ��㾭���������һ�������ġ���Ǯ��ټ����⡱������һ��
//ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̡�ĸ���������Σ�
void MoneyChicken()
{
	int cock = 0;
	int hen = 0;
	int chick = 0;
	
	cout << "When spend " << M << " to buy " << N << " chicks:" << endl;
	//��ٷ�
	for (cock = 0; cock <= 20; cock++)//������0~20
	{
		for (hen = 0; hen <= 33; hen++)//ĸ����0~33
		{
			for (chick = 3; chick <= 99; chick++)//С����3~99
			{
				if (5 * cock + hen * 3 + chick / 3 == M)//Ǯ��
				{
					if(cock + hen + chick == N)//����
						if (chick % 3 == 0)//�ж�С�����Ƿ�Ϊ3�ı���
						{
							cout << "Cockerel: " << cock << " Hen: " << hen\
								<< " Chick: " << chick << endl;
						}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////
//10.���һ������ 2011 �� 1 �� 1 �տ�ʼÿ�����һ���棬����ɹһ���������ʵ�ֵ����� 
//2011 1 �� 1 ���Ժ������һ�죬�����������ڴ��滹����ɹ��
bool IsLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}
int Days(int year, int month, int day)
{

	int sum = 0;
	int co[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };    
	int le[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };  

	//���������·�֮ǰ������
	if (IsLeap(year))
	{
		for (int i = 0; i < month; i++)
		{
			sum += le[i];
		}
	}
	else
	{
		for (int i = 0; i < month; i++)
		{
			sum += co[i];
		}
	}

	//�����������
	for (int i = YEAR; i < year; i++)
	{
		if (IsLeap(year))
		{
			sum += 366;
		}
		else
		{
			sum += 355;
		}
	}

	//���������µ�����
	sum += day;

	return sum;
}

void FishermanProblem()
{
	int year = 0;
	int month = 0;
	int day = 0;
	cout << "Please input year & month & day: ";
	cin >> year >> month >> day;

	int d = 0;
	d = Days(year, month, day);//ȷ������
	if ((d % 5) < 4 && (d % 5) > 0)
	{
		cout << "He is Fishing" << endl;
	}
	else
	{
		cout << "He is Sunneting" << endl;
	}
}

int main()
{
	////1.�ַ���������
	//ReverseString();
	////2.ģ��ʵ��strlen
	//MyStrlen();
	////3.n�Ľ׳�
	//Factorial();
	////4.�ֽ�����
	//Decomposition_Integer();
	////5.�ɱ������ƽ��ֵ
	//VariableParameters();
	////6.�ɱ���������ֵ
	//VariableParameters_Max();
	////7.����ˮ����
	//Dynamic_planning();
	////8.���ӳ���
	//EatPeach();
	////9.��Ǯ��׼�
	//MoneyChicken();
	////10.������ɹ��
	FishermanProblem();

	system("pause");
	return 0;
}