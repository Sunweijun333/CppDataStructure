#include <iostream>
#include "ThreeLetteList.h"
using namespace std;

//��������
class NodeB;
class NodeA
{
private:
	//������
	int data1;
	char data2;
	float data3;
	//�ڵ�ָ��
	NodeA *linka;
	NodeB *linkb;
};
class NodeB
{
private:
	int data;
	NodeB *link;
};

//������
class List;//ǰ������
class Node
{
	friend class List;//��Ԫ��
private:
	int data;//�ڵ��������
	Node *link;//ָ����һ���ڵ��ָ��
};
//����
class List
{
public:
	void test();
	void show();
private:
	Node *first;//ָ���һ���ڵ��ָ��
};
int main()
{
	List a;
	a.test();//������3���ڵ�
	a.show();
	ThreeLetterList l;
	l.test();
	l.show();
	system("pause");
	return 0;
}
void List::test()
{
	Node *f = new Node();//����һ���µĽڵ�
	f->data = 44;//����ʹ����Ԫ�����Ƕ����
	f->link = 0;
	first = f;

	f = new Node();
	f->data = 72;
	f->link = 0;

	first->link = f;

	f = new Node();
	f->data = 210;
	f->link = 0;

	first->link->link = f;
}

void List::show()
{
	cout << first->data << endl
		<< first->link->data << endl
		<< first->link->link->data<<endl;
}
