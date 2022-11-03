#include <iostream>

#include "../headers/Factory.h"
#include "../headers/Supplier.h"

int main()
{
	Factory factory;
	Supplier supplierA('A'), supplierB('B'), supplierC('C');
	char cont;

	factory.AddNewPartType(2);
	factory.AddNewPartType(3);

	do
	{
		std::cout << "Press Enter to Continue: ";
		std::cin.get(cont);
	} while (cont == '\n');

	return 0;
}