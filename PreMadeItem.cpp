#include "PreMadeItem.h"
#include "IceCreamItem.h"

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size) {
	this->name = name;
}

~PreMadeItem::PreMadeItem() {
}

std::string PreMadeItem::composeItem() {
	std::string result = "Pre-made Size: " + size;
	result += "\nPreMadeItem :";
	result += name;
	result += "\nPrice: $: ";
	result += price;
	result += "\n";
	return result;
}

int PreMadeItem::getPrice() {
	return price;
}
