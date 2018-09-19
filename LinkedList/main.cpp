#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> integers;

	for (int i = 1; i < 10; i++)
	{
		integers.Add(i);
	}
	for (int i = 0; i < integers.length(); i++)
	{
		std::cout << integers.GetValue(i) << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "index 1 : " <<integers[1] << std::endl << std::endl;

	std::cout << "After delete index 1" << std::endl;
	integers.Delete(1);
	for (int i = 0; i < integers.length(); i++)
	{
		std::cout << integers.GetValue(i) << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Add 545 in index 5" << std::endl;
	integers.Add(545, 5);
	for (int i = 0; i < integers.length(); i++)
	{
		std::cout << integers.GetValue(i) << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "First element : " << integers.first()->value() << std::endl << std::endl;
	integers.Delete(0);
	std::cout << "After delete first element" << std::endl;
	for (int i = 0; i < integers.length(); i++)
	{
		std::cout << integers.GetValue(i) << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "First element : " <<integers.first()->value() << std::endl << std::endl;

	std::cout << "Last element : " << integers.last()->value() << std::endl;
	integers.Delete(integers.length() - 1);
	std::cout << "After delete last element" << std::endl;
	for (int i = 0; i < integers.length(); i++)
	{
		std::cout << integers.GetValue(i) << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Last element : " << integers.last()->value() << std::endl;
	return 0;
}