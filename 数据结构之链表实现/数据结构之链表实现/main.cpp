#include <iostream>
#include <list> //STL�е�����
#include"List.h"
int main()
{
	List <int> intList;
	//��׼���е�����
	std::cout << "����STL�е�����͵�����:" << std::endl;
	std::list <int> ListIntegers;
	ListIntegers.push_front(5);
	ListIntegers.push_front(15); 
	ListIntegers.push_front(25);
	ListIntegers.push_front(35);
	std::list<int>::iterator i = ListIntegers.begin();
	std::cout << *i << "->";
	while (i != ListIntegers.end())
	{
		std::cout << *i << "->";
		++i;	
	}
	std::cout << std::endl;
	std::cout << "�ҵ�����͵�����:" << std::endl;
	//ǰ�����
	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	//intList.show();
	ListIterator <int> li(intList);
	if (li.NotNull())
	{
		std::cout << *li.first();
		while(li.NextNotNull())
			std::cout <<"->" <<*li.next();
		std::cout << std::endl;
	}
	system("Pause");
	return 0;
	intList.Invert();
	intList.show();
	intList.Delete(45);
	intList.show();
	List <char> charList;
	charList.Insert('a');
	charList.Insert('b');
	charList.Insert('c');
	charList.Insert('d');
	charList.show();
	charList.Invert();
	List <char> charList2;
	charList2.Insert('e');
	charList2.Insert('f');
	charList2.Insert('g');
	charList2.Insert('h');
	charList2.Invert();
	charList2.show();
	charList.Concatenate(charList2);
	charList.show();
	system("Pause");
	return 0;
}