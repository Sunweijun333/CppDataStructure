#include <iostream>

using namespace std;

int main()
{
	//��������ֵ�����ǵ�ַ
	int a, b, temp;
	a = 1;
	b = 10;
	cout << "a= "<< a << ", "<<"b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b<<endl;
	temp = a;
	a = b;
	b = temp;
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b<<endl;
	return 0;
} 