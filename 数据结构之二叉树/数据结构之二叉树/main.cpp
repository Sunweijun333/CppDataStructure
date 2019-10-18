#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree <char> tree;
	TreeNode <char> add, del, mul, dep,a,b,c,d,e;
	add.data = '+';
	del.data = '-';
	mul.data = '*';
	dep.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';
	tree.root = &add;
	add.leftChild = &del;
	add.rightChild = &e;
	del.leftChild = &mul;
	del.rightChild = &d;
	mul.leftChild = &dep;
	mul.rightChild = &c;
	dep.leftChild = &a;
	dep.rightChild = &b;

	cout << "�������:";
	tree.InOrder();
	cout << endl;

	cout << "ǰ�����:";
	tree.PreOrder();
	cout << endl;

	cout << "�������:";
	tree.PostOrder();
	cout << endl;
	
	cout << "�������:";
	tree.levelOrder();
	cout << endl;
	system("pause");
	return 0;

}