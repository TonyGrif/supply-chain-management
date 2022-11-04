#include <iostream>

#include "../headers/Factory.h"
#include "../headers/Supplier.h"

int main()
{
	Factory factory({1,2,3});
	Supplier supplierA({1}, 'A'), supplierB({2}, 'B'), supplierC({3}, 'C');
	Supplier sub_supplierD({1, 3}, 'D'), sub_supplierE({1, 2, 3}, 'E');
	char cont;

	do
	{
		std::cout << "Press Enter to Continue: ";
		std::cin.get(cont);
	} while (cont == '\n');

	return 0;
}