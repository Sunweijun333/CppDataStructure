#pragma once
#include <iostream>
//ʹ��Ƕ����
//class ThreeLetterNode;
//��������Բ����ڲ��������˽�г�Ա
class ThreeLetterList
{
private:
	//Ƕ����
	class ThreeLetterNode
	{
	//��Ҫ�ǹ��е�
	public:
		char data[3];
		ThreeLetterNode *link;
	};
	ThreeLetterNode *first;
	
public:
	void test();
	void show();
};

void ThreeLetterList::test()
{
	ThreeLetterNode *f = new ThreeLetterNode();
	//ThreeLetterNode *first=new ThreeLetterNode();//�˴����ܶ����µ�
	f->data[0] = 'B';
	f->data[1] = 'A';
	f->data[2] = 'T';
	f->link = 0;

	first = f;

	f = new ThreeLetterNode();
	f->data[0] = 'C';
	f->data[1] = 'A';
	f->data[2] = 'T';
	f->link = 0;

	first->link = f;
}

void ThreeLetterList::show()
{
	////ThreeLetterNode *first = new ThreeLetterNode();
	std::cout << first->data[0]
			  << first->data[1] 
		      << first->data[2]
			  << "->";
	std::cout << first->link->data[0]
		      << first->link->data[1]
		      << first->link->data[2]
			  << std::endl;
}
