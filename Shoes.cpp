#include "Shoes.h"

Shoes::Shoes(int vendor_code, string name, int size, int number_of_pairs, int cost, string name_factory, string delivery_time) : vendor_code_(vendor_code),
	name_(name), size_(size), number_of_pairs_(number_of_pairs), cost_(cost), name_factory_(name_factory), delivery_time_(delivery_time)
{ 
}

Shoes::Shoes() {
}


string const Shoes::GetName() {
	return name_;
}

int const Shoes::GetSize() {
	return size_;
}

string const Shoes::GetNameFactory() {
	return name_factory_;
}

void Shoes::Print() {
	PRINT(vendor_code_);
	PRINT(name_);
	PRINT(size_);
	PRINT(number_of_pairs_);
	PRINT(cost_);
	PRINT(name_factory_);
	PRINT(delivery_time_);
}
