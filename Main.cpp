#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Shoes.h"

using namespace std;
#define RUS SetConsoleCP(1251); SetConsoleOutputCP(1251); srand(time(NULL));

vector<string> split(string str, int d) {
    vector<string> v;
    while (str.find(d) != -1) {
        v.push_back(str.substr(0, str.find(d)));
        str.erase(0, str.find(d) + 1);
    }
    v.push_back(str);
    return v;
}

int CountInFile(string filename) {
    int counter = 0;
    char c;
    ifstream file;
    file.open(filename);
    while (!file.eof()) {
        file.get(c);
        if (c == '\n') counter++;
    }
    file.close();
    return counter - 1;
}


void ReadTransport(vector<unique_ptr<Shoes>>& v) {
	string temp;
	vector<string> p;
	ifstream file("shoes.csv");
	for (int i = 0; i < CountInFile("shoes.csv"); i++) {
			getline(file, temp);
			p = split(temp, ';');
			if (p[0] == "Shoes") {
				v.push_back(unique_ptr<Shoes>(
					new Shoes(
						stoi(p[1]), p[2], stoi(p[3]), stoi(p[4]), stoi(p[5]), p[6], p[7]
					)));
			}
		else {}
	}
	file.close();
}

void SearchName(vector<unique_ptr<Shoes>>& v) {
	string name;
	cout << "Enter product name: " << endl;
	cin >> name;
	for (auto& item : v) {
		if (name == item->GetName()) {
			cout << "Your products have been found." << endl;
		}
		else {
			cout << "ERROR. There are no products with that name." << endl;
		}
	}
}

void SearchSize(vector<unique_ptr<Shoes>>& v) {
	int size;
	cout << "Enter product size: " << endl;
	cin >> size;
	for (auto& item : v) {
		if (size == item->GetSize()) {
			cout << "Your products have been found." << endl;
		}
		else {
			cout << "ERROR. There are no products with that size." << endl;
		}
	}
}

void SearchFactoryName(vector<unique_ptr<Shoes>>& v) {
	string factoryname;
	cout << "Enter product factory name: " << endl;
	cin >> factoryname;
	for (auto& item : v) {
		if (factoryname == item->GetNameFactory()) {
			cout << "Your products have been found." << endl;
		}
		else {
			cout << "ERROR. There are no products with that factory name." << endl;
		}
	}
}

void SortingName(vector<unique_ptr<Shoes>>& v) {
	sort(v.begin(), v.end(), [](const unique_ptr<Shoes>& p1, const unique_ptr<Shoes>& p2) {
		return p1->GetName() > p2->GetName();
		});
	for (auto &item:v) {
		cout <<"Name: "<< item->GetName() << endl;
	}
}

void SortingSize(vector<unique_ptr<Shoes>>& v) {
	sort(v.begin(), v.end(), [](const unique_ptr<Shoes>& p1, const unique_ptr<Shoes>& p2) {
		return p1->GetSize() > p2->GetSize();
		});
	for (auto& item : v) {
		cout <<"Size: "<< item->GetSize() << endl;
	}
}

void Menu() {
	vector <unique_ptr<Shoes>> shoes;
	int choice;
	do {
		cout << "1.Print report." << endl;
		cout << "2.Search shoes by name." << endl;
		cout << "3.Search shoes by size." << endl;
		cout << "4.Search shoes by factory name." << endl;
		cout << "5.Sorting by shoe name." << endl;
		cout << "6.Sorting by shoe size." << endl;
		cout << "7.Shutdown." << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			ReadTransport(shoes);
			for (auto& item : shoes) item->Print();
			break;
		case 2:
			SearchName(shoes);
			break;
		case 3:
			SearchSize(shoes);
			break;
		case 4:
			SearchFactoryName(shoes);
			break;
		case 5:
			SortingName(shoes);
			break;
		case 6:
			SortingSize(shoes);
			break;
		case 7:
			cout << "You left the program." << endl;
			break;
		default:
			cout << "ERROR.The choice is uncertain. " << endl;
			break;
		}
	} while (choice != 7);
}

int main() {
	Menu();
	return 0;
}