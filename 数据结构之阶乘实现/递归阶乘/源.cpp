//递归很强大。。。
//计算n的阶乘
#include <iostream>

using namespace std;

long JieCheng(int n);

//递归算法 自己调用自己
long JieCheng(int n)
{
	if (n == 0)
		return 1;
	else
		return n*JieCheng(n - 1);
}
int main()
{
	cout << JieCheng(10);
	cin.get();
	return 0;
}