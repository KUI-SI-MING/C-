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

int main()
{
	////1.�ַ���������
	ReverseString();
	system("pause");
	return 0;
}