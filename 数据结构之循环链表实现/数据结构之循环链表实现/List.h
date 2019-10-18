#pragma once
//ѭ������-------------------------------------------------------
//ѭ������-------------------------------------------------------
//ѭ������-------------------------------------------------------
#include <iostream>
template <class Type> class List;//ǰ������
template <class Type> class ListIterator;//һ��Ҫ��ǰ������
										 //��ģ�����ģ����
template <class Type>
//ListNode ��ģ�������
class ListNode
{
	friend class List<Type>;//����Ҫ��<Type>
	friend class ListIterator <Type>;
private:
	Type data;//�ڵ������
	ListNode *link;//ָ����һ������ڵ�
	ListNode(Type);
	ListNode() {};//�޲����Ĺ��캯��
};

template <class Type>
class List
{
	friend class ListIterator <Type>;
public:
	List() { first = new ListNode<Type>; first->link = first; }//��ͷ
	void Insert(Type);
	void Delete(Type);
private:
	ListNode <Type> *first;
};

//������
template <class Type>
class ListIterator
{
public:
	ListIterator(const List <Type> & l) :list(l), current(l.first->link) {};
	bool NotNull();//������ǰ�ڵ��ǲ��ǿյ�
	bool NextNotNull();//������ǰ�ڵ����һ���ڵ��ǲ��ǿյ�
	Type *first();//���ص�ǰ�ڵ�ָ��
	Type *next();//������һ�ڵ��ָ��
private:
	const List<Type> &list;//���洫�������
	ListNode <Type> *current;//ָ��ǰ�Ľڵ�
};

template<class Type>
inline bool ListIterator<Type>::NotNull()
{
	if (current!=list.first)
		return true;
	else
		return false;
}

template <class Type>
inline bool ListIterator <Type>::NextNotNull()
{
	//�õ����������ĳ�Ա
	if ((current->link)!= list.first)
		return true;
	else
		return false;
}

//���ص�ǰ�ڵ�ָ��
template <class Type>
inline Type *ListIterator<Type>::first()
{
	if (current!=list.first)
		return &current->data;
	else
		return 0;
}

//���ص�ǰ�ڵ����һ���ڵ�ָ��
template<class Type>
inline Type * ListIterator<Type>::next()
{
	current = current->link;
	if (current == list.first)
	{
		current = current->link;
		return &current->data;
	}
}

//����
template <class Type>
void List <Type>::Insert(Type k)
{
	ListNode <Type> *newnode = new ListNode<Type>(k);//�����µĽڵ�
	//�ڱ�ͷ����ӽڵ�
	newnode->link = first->link;
	first->link = newnode;
}

//ɾ��
template<class Type>
inline void List<Type>::Delete(Type k)
{
	ListNode <Type> *Previous = first;//ǰһ��ָ��
	ListNode <Type> *current;
	for (current = first->link; (current!=first)&&current&&current->data != k;
		Previous = current, current = current->link)
	{
		;//��ѭ�����ҵ�Ҫ��ɾ���Ľڵ�
	}
	if (current!=first)
	{
		//if (Previous) Previous->link = current->link;
		//else first = first->link;
		Previous->link = current->link;
		delete current;//ɾ������ڵ�ָ��
	}
	else
	{
		std::cout << "������û���������,лл";
	}
}
template <class Type>
ListNode <Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}
