#include <map>
#include "CustomItem.h"
#include "IceCreamItem.h"

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {
	toppings = new std::map<std::string, int>;
}

~CustomItem::CustomItem() {
	delete toppings;
}

void CustomItem::addTopping(std::string topping) {
	map<std::string, int>::iterator i = toppings->find(topping);
	if (i != toppings->end()) {
		i->second++;
	} else {
		toppings->insert(new std::Pair(topping, 1));
	}
	changePrice(.4);
}

std::string CustomItem::composeItem() {
	std::string result = "Custom Size: " + size;
	result += "\nToppings:";
	for (map<std::string, int> i = toppings->begin(); i != toppings->end(); i++) {
		result += i->first;
		result += ": ";
		result += i->second;
		result += " oz\n";
	}
	result += "\nPrice: $: ";
	result += price;
	result += "\n";
	return result;
}

int CustomItem::getPrice() {
	return price;
}
