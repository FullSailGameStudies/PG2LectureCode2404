#include "Inventory.h"
#include <iostream>

void Inventory::Show() const
{
	std::cout << "\n\n# of items: " << Count() << "\n";
	for (auto& item : items_)
	{
		std::cout << item << "\n";
	}
}
