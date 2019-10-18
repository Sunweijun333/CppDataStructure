#pragma once
template <class T> class LinkedStack;//ǰ������

template <class T>
class ChainNode 
{
	friend class LinkedStack <T>;
private:
	ChainNode(const T & theData, ChainNode *n = 0) 
		:data(theData), link(n) {}
	T data;
	ChainNode <T> *link;//ָ����һ���ڵ�

};

template <class T>
class LinkedStack
{
public:
	LinkedStack() :topp(0) {}
	~LinkedStack() { makeEmpty(); }
	bool IsEmpty()const;
	T &top() const;//�鿴ջ��top������ı����ظ���
	void Pop();//��ջ
	void Push(const T &e);
	void makeEmpty();
private:
	ChainNode <T> *topp;

};

template<class T>
inline bool LinkedStack<T>::IsEmpty() const
{	
	return topp==0;
}

template<class T>
inline T & LinkedStack<T>::top() const
{
	// TODO: �ڴ˴����� return ���
	if (this->IsEmpty())
		throw "��ջ�ǿյ�";
	else
		return topp->data;
}

template<class T>
inline void LinkedStack<T>::Pop()
{
	if (this->IsEmpty())
		throw "��ջ�ǿյģ�����ɾ��";
	ChainNode <T> *delNode = topp;
	topp = topp->link;
	delete delNode;//һ��Ҫ�������
}

template<class T>
inline void LinkedStack<T>::makeEmpty()
{
	while (!IsEmpty())
		Pop();
}

template<class T>
inline void LinkedStack<T>::Push(const T & e)
{
	//ģ����
	topp = new ChainNode <T> (e, topp);
}
