//����������ͨѭ�����κ�ʹ�õݹ�Ķ�����ʹ��ѭ����������
#include <iostream>

using namespace std;

long DieDai(int n)
{
	long res = 1;
	for (int i = n; i>0; i--)
	{
		res = res*i;
	}
	return res;
}
int main()
{
	cout << DieDai(10);
	cin.get();
	return 0;
}