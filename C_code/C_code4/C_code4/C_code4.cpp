#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#define N 100

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

int main()
{
	////1.�ַ���������
	//ReverseString();
	////2.ģ��ʵ��strlen
	MyStrlen();

	system("pause");
	return 0;
}