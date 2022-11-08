#include <iostream>

#include "../headers/Factory.h"
#include "../headers/Supplier.h"

int main()
{
	Factory factory({1,2,3});
	Supplier* ptrA = new Supplier({1}, 'A');
	Supplier* ptrB = new Supplier({2}, 'B');
	Supplier* ptrC = new Supplier({3}, 'C');
	char cont;

	factory.AddSupplier(ptrA);
	factory.AddSupplier(ptrB);
	factory.AddSupplier(ptrC);

	do
	{
		factory.TimeStep();


		std::cout << "Press Enter to Continue: ";
		std::cin.get(cont);
	} while (cont == '\n');

	return 0;
}