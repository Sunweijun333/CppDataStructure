#include <iostream>

using namespace std;
void ��(int *list, const int n);

int main()
{
	int x[] = { 1, 2, 5, 1, 4, 5, 7, 8, 9, 0 };
	cout << "����֮ǰ" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	��(x, 10);
	cout << "����֮��" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	cin.get();
	return 0;
}
void ��(int *list, const int n)
{
	//�Ľ� i<n-1
	for (int i = 0; i < n-1; i++)//�ҳ���С
	{
		int min = i;//�ȼ����һ������С��,min���±꣬�����С
		for (int j = i+1; j < n; j++)
		{
			if (list[j] < list[min])
				min = j;
		}
		swap(list[i], list[min]);//����
	}
}