#include <iostream>
#include "MyUtil.h"
#include "MyStack.h"
#include <string>

using namespace std;
class dog
{

};
int main()
{
	MyStack<int> st;//��������
	MyStack<string> myStringStack;//�ַ���
	MyStack<dog> dogStack;//����
	st.Push(99);
	st.Push(22);
	st.Push(67);
	st.Push(33);
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	cout << "test";
	cin.get();
	return 0;
}