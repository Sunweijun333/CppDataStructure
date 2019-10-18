#pragma once
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
};

template <class Type>
class List
{
	friend class ListIterator <Type>;
public:
	List() { first = 0; };
	void Insert(Type);
	void Delete(Type);
	void Invert();//��ת
	void Concatenate(List<Type>);//�ϲ�
	void show();
private:
	ListNode <Type> *first;
};
template <class Type>
class ListIterator
{
public:
	ListIterator(const List <Type> & l) :list(l), current(l.first) {};
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
	if (current) 
		return true;
	else
		return false;
}

template <class Type>
inline bool ListIterator <Type>::NextNotNull()
{
	if (current &&current->link) 
		return true;
	else
		return false;
}

//����ָ��
template <class Type>
inline Type *ListIterator<Type>::first()
{
	if (list.first)
		return &list.first->data;
	else
		return 0;
}

template<class Type>
inline Type * ListIterator<Type>::next()
{
	if (current)
	{
		current = current->link;
		return &current->data;
	}
	else
	return NULL;
}

template <class Type>
void List <Type>::Insert(Type k)
{
	ListNode <Type> *newnode = new ListNode<Type>(k);
	newnode->link = first;
	first = newnode;
}

template<class Type>
inline void List<Type>::Delete(Type k)
{
	ListNode <Type> *Previous = 0;//ǰһ��ָ��
	ListNode <Type> *current;
	for(current=first;current&&current->data!=k;
		Previous=current, current = current->link)
	{
		//��ѭ�����ҵ�Ҫ��ɾ���Ľڵ�
	}
	if (current)
	{
		if (Previous) Previous->link = current->link;
		else first = first->link;
		delete current;//ɾ������ڵ�ָ��
	}
	else
	{
		std::cout << "������û���������,лл";
	}
}

//��ת
template<class Type>
inline void List<Type>::Invert()
{
	ListNode <Type> *p = first, *q = 0;
	while (p)
	{
		ListNode<Type> *r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}

//�ϲ�
template<class Type>
inline void List<Type>::Concatenate(List<Type> b)
{
	if (!first) { first = b.first; return; }
	if (b.first)
	{
		ListNode <Type> *p;
		for (p = first; p->link; p = p->link)
		{
			//�ҵ����һ���ڵ�
		}
		p->link = b.first;
	}
}

template<class Type>
inline void List<Type>::show()
{
	for (ListNode<Type> *current = first; current; current = current->link)
	{
		std::cout << current->data;
		if (current->link) std::cout << "->";
	}
	std::cout << std::endl;
}

template <class Type>
ListNode <Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}