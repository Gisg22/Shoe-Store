#pragma once
#include <iostream>
#define PRINT(x) cout<<(#x)<<" : "<<x<<endl;
using namespace std;

class Shoes
{
public:
	Shoes(int vendor_code, string name, int size, int number_of_pairs, int cost, string name_factory, string delivery_time);
	Shoes();
	string const GetName();
	int const GetSize();
	string const GetNameFactory();
	void Print();
private:
	int vendor_code_;
	string name_;
	int size_;
	int number_of_pairs_; //количество пар.
	int cost_;
	string name_factory_;
	string delivery_time_; //срок поставки
};

