//#pragma once
#include "MyUtil.h"
#ifndef _MYSTACK_H
#define _MYSTACK_H
//��ģ��
template <class T>
class MyStack
{
public:
	MyStack(int stackCapacity = 10);
	~MyStack();
	inline bool IsEmpty() const;
	T &Top()const;
	void Push(const T &item);
	inline void Pop();

private:
	T *stack;
	int top;//��¼ջ����λ��
	int capacity;
};
//ʵ��
template <class T>
MyStack <T>::MyStack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "stack capacity must be >0";
	stack = new T[capacity];
	top = -1;
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}

template<class T>
//��������
inline bool MyStack<T>::IsEmpty() const
{
	return top == -1;
}

template<class T>
inline T & MyStack<T>::Top() const
{
	// TODO: �ڴ˴����� return ���
	if (IsEmpty()) throw "stack is empty";
	return stack[top];
}

template<class T>
void MyStack<T>::Push(const T & item)
{
	if (top == capacity - 1)
	{
		ChangeSizeID(stack, capacity, 2 * capacity);
		capacity = 2 * capacity;
	}
	stack[++top] = item;
}
template<class T>
//ɾ��ջ��
void MyStack<T>::Pop()
{
	if (IsEmpty()) throw "stack is empty. Cannot delete";
	//����Ƕ���ɾ��֮��Ҫ����
	//stack[top--].~MyStack();
	stack[top--].~T();//��Ҳ�С���
}
#endif // !_MYSTACK_H
