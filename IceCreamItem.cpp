#include "IceCreamItem.h"

#ifndef ICECREAMITEM_H
#define ICECREAMITEM_H

class IceCreamItem {
	// Constructor for an IceCreamItem. All ice cream items
	// will either be "small", "medium", or "large".
	IceCreamItem::IceCreamItem(std::string size) {
		this->size = size;
		price = size == "small" ? 3 : size == "medium" ? 5 : size == "large" ? 6.5 : 0;
	}

	// A virtual method that composes a string with the details
	// of an IceCreamItem. See the lab writeup and test files
	// for examples of the format for composeItem.
	std::string IceCreamItem::composeItem() {
		std::string result = "Custom Size: ";
		result += size;
		result += "\nPrice: $: ";
		result += price;
		result += "\n";
		return result;
	}

	// Returns the dollar amount of an ice cream item.
	double IceCreamItem::getPrice() {
		return price;
	}
};

#endif
