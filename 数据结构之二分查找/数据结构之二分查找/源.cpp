#include <iostream>

using namespace std;
int BinarySearch(int *a, const int x, const int n);
int main()
{
	int x[] = { 0,1,2,4,5,6,7,7,7,7,7,7,8,9,10 };
	int res,num=11;
	res = BinarySearch(x, 7, 10);
	if (res < 0)
		cout << "û�ҵ�" << endl;
	else
		cout << "��x[" << res << "]�ҵ�" << num << endl;
	cin.get();
	return 0;
}
//���ֲ����㷨�ٶȺܿ죬����Ҫ����������,���ظ����ݣ�����ֻ���ҳ�һ��
int BinarySearch(int *a, const int x, const int n)
{
	int low, high, mid;
	low = 0, high = n - 1;
	while (low<=high)
	{
		mid = (low + high) / 2;
		cout << mid << endl;
		if (a[mid]==x)
		{
			return mid;
		}
		else if (a[mid] < x)
		{
			low = mid + 1;
		}
		else if (a[mid] > x)
		{
			high = mid - 1;
		}
	}
	return -1;
}