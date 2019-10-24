#include <iostream>

using namespace std;

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void swap(int x, int y);
void swap_ref(int &, int &); //
void swap_poi(int *x, int *y);

int main()
{
	int a, b,t;
	a = 1;
	b = 10;
	cout << "swap:" << endl;
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	//���ɹ� 
	swap(a, b);//���ݲ����ķ�ʽӰ�죬��a��b����һ��������ȥ��������
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	cout << "swap_ref:" << endl;
	swap_ref(a, b);//���ݲ����ķ�ʽӰ�죬��a��b����һ��������ȥ��������
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	cout << "swap_pointer:" << endl;
	swap_poi(&a, &b);//���ݲ����ķ�ʽӰ�죬��a��b����һ��������ȥ��������
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	cout << "�꺯��:" << endl;
	SWAP(a, b,t);//���ݲ����ķ�ʽӰ�죬��a��b����һ��������ȥ��������
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	cout << "ģ�庯��:" << endl;
	SWAP(a, b, t);//���ݲ����ķ�ʽӰ�죬��a��b����һ��������ȥ��������
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a ��ַ��" << &a << endl << "b ��ַ��" << &b << endl;
	system("pause");
	return 0;
}

//�˷������ܽ���
void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
//��ָ��
void swap_poi(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//������
void swap_ref(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}