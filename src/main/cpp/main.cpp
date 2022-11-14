#include <iostream>

#include "../headers/Factory.h"
#include "../headers/Supplier.h"

int main()
{
	Factory factory({1,2,3});
	// Giving them different production rates to demonstrate adding and removing parts does work 
	Supplier* ptrA = new Supplier({1}, 'A', 1);
	Supplier* ptrB = new Supplier({2}, 'B', 2);
	Supplier* ptrC = new Supplier({3}, 'C', 3);
	char cont;

	factory.AddSupplier(ptrA);
	factory.AddSupplier(ptrB);
	factory.AddSupplier(ptrC);

	do
	{
		factory.TimeStep();

		std::cout << factory.toString() << std::endl;

		std::cout << "Press Enter to Continue: ";
		std::cin.get(cont);
	} while (cont == '\n');

	return 0;
}