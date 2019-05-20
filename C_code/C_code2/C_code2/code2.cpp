#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace::std;

////////////////////////////////////////////////////////
//1.��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222 
void Sum()
{
	int num = 0;//����
	int count = 0;//����
	cout << "Please input number of items : ";
	cin >> num >> count;

	int sum = 0;
	int n = num;
	for (int i = 0; i < count; i++)
	{
		sum += n;
		n = n * 10 + 2;
	}

	cout << "The resaults is: " << sum << endl;
}

////////////////////////////////////////////////////////
//2.�ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ���
void TestCurlyBraces()
{
	cout << "Please input CurlyBraces: ";
	string bra;
	getline(cin, bra);

	int leftbraces = 0;//��������Ŀ
	int rightbraces = 0;//��������
	for (int i = 0; i < bra.size(); i++)
	{
		if (bra[i] == '{')
		{
			leftbraces++;
		}
		else
		{
			rightbraces++;
		}
	}
	if (leftbraces != rightbraces)
	{
		cout << "Is not Into pairs" << endl;
	}
	else
	{
		//��������������ͬʱ����������˳���磺{}{},}}{{
		for (int i = 0; i < leftbraces; i++)
		{
			if (bra[i] != '{')
			{
				cout << "Is not Into pairs" << endl;
				return;
			}
		}
		cout << "Is Into pairs" << endl;
	}

}

////////////////////////////////////////////////////////
//3.дһ���������ز����������� 1 �ĸ���
void Count_One_Bit()
{
	//��ȡλ�ж�
	unsigned int num = 0;
	int cou = 0;

	cout << "Please inout a number: ";
	cin >> num;

	//�洢ʱ����4294967295�����Զ���Ϊ4294967295,������Ϊ�޷�����ʱֵ�����ѱ���-1���Ϊ4294967295
	if ( (int)num < 0 || (int)num > 4294967295)
	{
		cout << "Exceeding range!" << endl;
		return;
	}

	for (int i = 0; i < 32; i++)
	{
		if ((num >> i) & 1 == 1)
		{
			cou++;
		}
	}

	cout << "The number if the '1' is: " << cou << endl << endl;
	//��num & (num - 1)����
	cou = 0;
	unsigned int tmp = num;
	while (tmp)
	{
		cou++;
		tmp &= (tmp - 1);///ÿ����һ�Σ�value�����Ƶ�λ��1�ͼ���һ��ֱ��value=0
	}
	cout << "The number if the '1' is: " << cou << endl;
}

////////////////////////////////////////////////////////
//4.��ȡһ�������������������е�ż��λ������λ���ֱ��������������
void Determine_OE()
{
	int num = 0;

	cout << "Please inout a number: ";
	cin >> num;
	vector<int> odd, even;

	if(num < (int)-2147483648 || num > (int)2147483647)
	{
		cout << "Exceeding ranger!" << endl;
		return;
	}

	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			even.push_back(((num >> i) & 1));
		}
		else
		{
			odd.push_back(((num >> i) & 1));
		}
	}

	cout << "The even of elements is: ";
	for (int i = 0; i < even.size(); i++)
	{
		cout << ' ' << even[i];
	} 
	cout << endl << "The odd of elements is: ";
	for (int i = 0; i < odd.size(); i++)
	{
		cout << ' ' << odd[i];
	}

	cout << endl;
}

////////////////////////////////////////////////////////
//5.����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ
void DifferentBit()
{
	int n1 = 0, n2 = 0;
	cout << "please input two number: ";
	cin >> n1 >> n2;

	if (n1 < (int)-2147483648 || n1 >(int)2147483647 || n2 < (int)-2147483648 || n2 >(int)2147483647)
	{
		cout << "Exceeding ranger!" << endl;
		return;
	}

	int cou = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((n1 >> i) & 1) != ((n2 >> i) & 1))
			cou++;
	}

	cout << "The different bit count is: " << cou << endl;
}

////////////////////////////////////////////////////////
//6.��ˮ����
void MatchRanking()
{

}
int main()
{

	////1.ǰn��֮��
	//Sum();
	////2.��֤������
	//TestCurlyBraces();
	////3.1�ĸ���
	//Count_One_Bit();
	////4.��ż�ж�
	//Determine_OE();
	////5.��ͬ����λ
	//DifferentBit();
	////6.��ˮ����
	MatchRanking();


	system("pause");
	return 0;
}