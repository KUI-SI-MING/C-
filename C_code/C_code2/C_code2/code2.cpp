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

	cout << "The even bit of elements is: ";
	for (int i = 0; i < even.size(); i++)
	{
		cout << ' ' << even[i];
	} 
	cout << endl << "The odd bit of elements is: ";
	for (int i = 0; i < odd.size(); i++)
	{
		cout << ' ' << odd[i];
	}

	cout << endl;
}

////////////////////////////////////////////////////////
//5.����int��32λ������m��n�Ķ����Ʊ����У��ж��ٸ�λ(bit)��ͬ
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
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������
int Forecast(int arr[])//�ж�Ԥ����
{
	if ((arr[1] == 2) + (arr[0] == 3) == 1
		&& (arr[1] == 2) + (arr[4] == 4) == 1
		&& (arr[2] == 1) + (arr[3] == 2) == 1
		&& (arr[2] == 5) + (arr[3] == 3) == 1
		&& (arr[4] == 4) + (arr[0] == 1) == 1)
		return 1;
	else
		return 0;
}
int Repetition(int arr[])//�ж������Ƿ��ظ�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
		for (j = i + 1; j < 5; j++)
		{
			if (arr[i] == arr[j])
				return 0;
		}
	return 1;
}
void MatchRanking()
{
	int arr[5] = { 0 };
	//����arr[0]~arr[4]�ֱ����A B C D E  
	//arr[i]��ֵ��ʾ������ 
	//��������ҵ�Ψһ���
	for (arr[0] = 1; arr[0] <= 5; arr[0]++)
	{
		for (arr[1] = 1; arr[1] <= 5; arr[1]++)
		{
			for (arr[2] = 1; arr[2] <= 5; arr[2]++)
			{
				for (arr[3] = 1; arr[3] <= 5; arr[3]++)
				{
					for (arr[4] = 1; arr[4] <= 5; arr[4]++)
					{
						if (Forecast(arr) == 1)
							if (Repetition(arr) != 0)
							{
								cout << "A:Ϊ�� " << arr[0] << "��" << endl;
								cout << "B:Ϊ�� " << arr[1] << "��" << endl;
								cout << "C:Ϊ�� " << arr[2] << "��" << endl;
								cout << "D:Ϊ�� " << arr[3] << "��" << endl;
								cout << "E:Ϊ�� " << arr[4] << "��" << endl;
							}
					}
				}
			}
		}
	}
}

////////////////////////////////////////////////////////
//7.�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ�
//��һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ�
void FindKiller()
{
	char killer = '0';
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		//���������� һ��������
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
		{
			cout << "The killer is: " << killer << endl;
		}
	}
}

////////////////////////////////////////////////////////
//8.��ӡ�������
void PrintYangHuiTriangle()
{

}

////////////////////////////////////////////////////////
//9.�÷��η������ֵ
int FindMax(const vector<int> a, int left, int right)
{
	int fm = 0;//��һ�������ֵ
	int sm = 0;//�ڶ��������ֵ

	if (left == right)
		return a[left];

	int mid = (left + right) / 2;
	fm = FindMax(a, left, mid);
	sm = FindMax(a, mid + 1, right);

	return fm > sm ? fm : sm;

}
void MaxValue()
{
	int size = 0;
	cout << "Please input arr elements counts: ";
	cin >> size;

	cout << "Please input arr elements: ";
	vector<int> arr;
	for (int i = 0; i < size; i++)
	{
		int data = 0;
		cin >> data;
		arr.push_back(data);
	}

	int max = FindMax(arr, 0, size - 1);
	cout << "The max value is: " << max << endl;
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
	//MatchRanking();
	////7.ɱ������
	//FindKiller();
	////8.�������
	//PrintYangHuiTriangle();
	////9.�������ֵ
	MaxValue();



	system("pause");
	return 0;
}