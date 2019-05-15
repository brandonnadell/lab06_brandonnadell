#include "PreMadeItem.h"
#include <iomanip>
#include <sstream>

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size) {
	this->name = name;
	price = size == "small" ? 4 : size == "medium" ? 6 : size == "large" ? 7.5 : 0;
}

PreMadeItem::~PreMadeItem() {
}

std::string PreMadeItem::composeItem() {
	std::string result = "Pre-made Size: " + size;
	result += "\nPre-made Item: ";
	result += name;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << price;
	result += "\nPrice: $" + stream.str() + "\n";
	return result;
}

double PreMadeItem::getPrice() {
	return price;
}
