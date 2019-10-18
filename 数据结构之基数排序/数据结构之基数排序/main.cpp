#include <iostream>
#include <list>

using namespace std;
//�ж��������Ƕ���λ
int maxdigit(int data[], int n)
{
	int d = 1;
	int p = 10;
	for (int i=0;  i< n; i++)
	{ 
		while (data[i]>=p)
		{
			p *= 10;
			++d;
		}	
	}
	return d;
}
//��������
void radixsort(int data[], int n)
{
	int digits = maxdigit(data, n);
	list <int> lists[10];
	int d, j, k, factor;
	//ѭ������
	for (d = 1,factor=1; d <= digits; factor*=10,d++)
	{
		for (j = 0; j < n; j++)
		{
			lists[(data[j] / factor) % 10].push_back(data[j]);
		}
		for (j=k=0;j<10;j++)
		{
			while (!lists[j].empty())
			{
				//ȥһ��ɾһ��
				data[k++] = lists[j].front();
				lists[j].pop_front();
			}
		}
	}
}
int main()
{
	int data[] = { 179,208,306,93,859,984,55,9,271,33 };
	radixsort(data, 10);
	for (int i = 0; i < 10; i++)
		cout << data[i] << endl;
	cout << "test" << endl;
	system("pause");
	return 0;
}