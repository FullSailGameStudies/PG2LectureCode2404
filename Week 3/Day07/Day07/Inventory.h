#pragma once
#include <vector>
#include <string>
class Inventory
{
public:
	Inventory(const std::vector<std::string>& items) : 
		items_(items)//member initialization list
	{
	}

	int Count() const { return items_.size(); }
	std::vector<std::string> Items() const { return items_; }
	void Items(const std::vector<std::string>& items)
	{
		//maybe put some checks on the vector coming in
		items_ = items;
	}

	void Show() const;

private:
	std::vector<std::string> items_;
};

