#include <iostream>
#include <list> //STL�е�����
#include"List.h"
int main()
{
	List <int> intList;
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
		while (li.NextNotNull())
			std::cout << "->" << *li.next();
		std::cout << std::endl;
	}
	std::cout << "����һ��ѭ��";
	ListIterator <int> Iter(intList);
	std::cout << *Iter.first() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	system("Pause");
	return 0;
}