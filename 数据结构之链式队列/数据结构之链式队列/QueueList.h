#pragma once
//
//struct��Ϊ���ݽṹ��ʵ���壬��Ĭ�ϵ����ݷ��ʿ�����public�ģ�
//��class��Ϊ�����ʵ���壬��Ĭ�ϵĳ�Ա�������ʿ�����private��
template <class Object>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty()const;
	const Object & getFront() const;//ȡ�����׵�����
	void enqueue(const Object & x);//��β�����
	Object dequeue();//����,�Ӷ���ɾ��
	void makeEmpty();//�������
private:
	//�ڵ㣺�ڲ���
	struct ListNode
	{
		Object element;
		ListNode *next;
		ListNode(const Object & theElement, ListNode *n = 0)
			:element(theElement), next(n) {}
	};
	ListNode *front;
	ListNode *back;
};

//���캯��
template<class Object>
inline Queue<Object>::Queue()
{
	front = back = 0;
}

//�����������������
template<class Object>
inline Queue<Object>::~Queue()
{
	makeEmpty();
}

//�ж϶����Ƿ�Ϊ��
template<class Object>
inline bool Queue<Object>::isEmpty() const
{
	return  front==0;
}

template<class Object>
inline const Object & Queue<Object>::getFront() const
{
	// TODO: �ڴ˴����� return ���
	if (isEmpty())
		throw "�ն���";
	else
		return front->element;
}

//���
template<class Object>
inline void Queue<Object>::enqueue(const Object & x)
{
	if (isEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

//����
template<class Object>
inline Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();
	ListNode *old = front;
	front = front->next;
	delete old;
	return frontItem;
}

//makeEmpty()
template<class Object>
inline void Queue<Object>::makeEmpty()
{
	while (!isEmpty())
	{
		//������
		dequeue();
	}
}
