#include <iostream>

using namespace std;
int SequentialSearch(int *a, const int n, const int x);
int main()
{
	int m[] = { 1,5,4,6,3,2,9,8,7,0 };
	int res;
	int num = 7;
	res = SequentialSearch(m, 10, num);
	if (res < 0)
		cout << "û�ҵ�" << endl;
	else
		cout << "��m[" << res << "]���ҵ�" << num << endl;
	cin.get();
	return 0;
}
//���û�����������
int SequentialSearch(int *a, const int n, const int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	if (i == n)
		return -1;
}