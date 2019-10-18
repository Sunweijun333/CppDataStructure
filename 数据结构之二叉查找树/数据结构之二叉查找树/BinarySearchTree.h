#pragma once
#include <iostream>

enum boolean {FALSE,TRUE};

template <class Type>
class Element
{
public:
	Type Key;
	//��Ӹ��������
};

template <class Type> class Bst;
//�ڵ�
template <class Type>
class BstNode
{
public:
	friend class Bst <Type>;
//private:
	Element <Type> data;//˽�е�����ֻ�����������Ԫ���з���
	BstNode *leftChild;
	BstNode *rightChild;
	void display(int i);
};

template <class Type>
class Bst
{
public:
	Bst(BstNode <Type> *init = 0)
	{
		root = init;
	}
	boolean Insert(const Element <Type> & x);
	BstNode <Type>* Search(const Element <Type> & x);
	BstNode <Type>* Search(BstNode <Type> *,const Element <Type> & x);
	BstNode <Type>* IterSearch(const Element <Type> & );//�ǵݹ鷽ʽ
private:
	BstNode <Type> *root;
};

//��ʾ��ǰ�ڵ����ݣ������������������е�����
template<class Type>
inline void BstNode<Type>::display(int i)
{
	//�ݹ�
	std::cout << "Position: " << i << ", data.key=" << data.Key<<"\n";
	if (leftChild) leftChild->display(2*i);
	if (rightChild) rightChild->display(2 * i + 1);
}

//����
template<class Type>
inline boolean Bst<Type>::Insert(const Element<Type>& x)
{
	BstNode <Type> *p = root;
	BstNode <Type> *q = 0;//qָ��ǰ�ڵ�ĸ��ڵ�
	//����֮ǰҪ����
	while (p)
	{
		//����p;
		q = p;
		//�ظ���ʧ��
		if (x.Key == p->data.Key) 
			return FALSE;
		else if (x.Key < p->data.Key)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	//�ҵ���λ�þ���q;
	p = new BstNode <Type>;
	p->leftChild =p->rightChild= 0;
	p->data = x;
	if (!root) root = p;
	else if (x.Key < q->data.Key) q->leftChild = p;
	else if (x.Key > q->data.Key) q->rightChild = p;
	return TRUE;
}

template<class Type>
inline BstNode<Type>* Bst<Type>::Search(const Element<Type>& x)
{
	return Search(root, x);
}

//��ʼ�ݹ����
template<class Type>
inline BstNode<Type>* Bst<Type>::Search(BstNode<Type>* b, const Element<Type>& x)
{
	if (!b) return 0;
	if (x.Key == b->data.Key) return b;
	if (x.Key < b->data.Key) 
		return Search(b->leftChild,x);
	else
		return Search(b->rightChild, x);
}

//�������ҷ���
template<class Type>
inline BstNode<Type>* Bst<Type>::IterSearch(const Element<Type> & x)
{
	for (BstNode<Type> *t = root; t;)
	{
		if (x.Key == t->data.Key) 
			return t;
		if (x.Key < t->data.Key)
			t = t->leftChild;
		else
			t = t->rightChild;	
	}
	return 0;
}
