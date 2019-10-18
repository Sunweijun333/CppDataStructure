#pragma once
//ʹ��ģ����
template <class T>
class Queue
{	
public:
	Queue(int QueueCapacity = 10);
	~Queue();
	bool IsEmpty() const;
	T &Front() const;//�鿴���׵�����
	T &Rear() const;//�鿴��β������
	void Push(const T &item);//�ڶ�β��������
	void Pop();//ɾ����������
private:
	T *queue;
	int front;
	int rear;
	int capacity;
};

template <class T>
Queue<T>::Queue(int QueueCapacity):capacity(QueueCapacity)
{
	if (capacity < 1) throw "Quene capacity must be >0 ";
	queue = new T[capacity];
	front = rear = 0;//��ʼ��ʱ����׶�β��ָ��0
}

template<class T>
inline Queue<T>::~Queue()
{
}
template<class T>

//�ж��Ƿ�Ϊ��
inline bool Queue<T>::IsEmpty() const
{
	return front==rear;
}
template<class T>

//�鿴����+1������
inline T & Queue<T>::Front() const
{
	// TODO: �ڴ˴����� return ���
	if (IsEmpty()) throw "queue is Empty ";
	//�������
	return queue[(front+1)%capacity];
}
template<class T>
//����β����

inline T & Queue<T>::Rear() const
{
	// TODO: �ڴ˴����� return ���
	if (IsEmpty()) throw "queue is Empty ";
	return queue[rear];
}

template<class T>
//�������
void Queue<T>::Push(const T &item)
{
	//if (rear == capacity - 1)//��������һ��
	//{
	//	rear = 0;
	//}
	//else
	//{
	//	rear++;
	//}
	if ((rear + 1) % capacity == front)//�ж϶����Ƿ�����
	{
		//�ӱ����ص㣬�ӱ����ص㣬�ӱ����ص�
		T *newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)//û�л�ת
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue+capacity-start);
		}
		//�������ö���
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		//ɾ��ԭ��������
		delete[] queue;
		//�ı�ָ���ָ��
		queue = newQueue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

template<class T>
//ɾ�����׵�����
inline void Queue<T>::Pop()
{
	if (IsEmpty()) throw "queue is Empty ";
	front = (front + 1) % capacity;//�߼�
	queue[front].~T();
}