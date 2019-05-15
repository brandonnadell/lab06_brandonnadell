#include <map>
#include <iomanip>
#include <sstream>
#include "CustomItem.h"

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {
	toppings = new std::map<std::string, int>;
	price = size == "small" ? 3 : size == "medium" ? 5 : size == "large" ? 6.5 : 0;
}

CustomItem::~CustomItem() {
	delete toppings;
}

void CustomItem::addTopping(std::string topping) {
	std::map<std::string, int>::iterator i = toppings->find(topping);
	if (i != toppings->end()) {
		i->second++;
	} else {
		toppings->insert(std::pair<std::string, int>(topping, 1));
	}
	price += .4;
}

std::string CustomItem::composeItem() {
	std::string result = "Custom Size: " + size;
	result += "\nToppings:\n";
	std::stringstream stream;
	for (std::map<std::string, int>::iterator i = toppings->begin(); i != toppings->end(); i++) {
		stream << i->first;
		stream << ": ";
		stream << i->second;
		stream << " oz\n";
	}
	stream << "Price: $";
	stream << std::fixed << std::setprecision(2) << price;
	result += stream.str() + "\n";
	return result;
}

double CustomItem::getPrice() {
	return price;
}
