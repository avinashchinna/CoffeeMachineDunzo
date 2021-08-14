#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "machine.h"
#include<iomanip>

template<typename T> void print(T t, const int& width, const char& seperator)
{
	cout << left << setw(width) << setfill(seperator) << t;
}

void DisplayInventory(Machine& machine) {
	const int width = 20;
	const int numWidth = 9;
	const int div_width = 4;
	const char seperator = ' ';
	map<string, int> availableIngredients = machine.getAvailableIngredients();
	for (auto itr:availableIngredients) {
		print("||", div_width, seperator);
		print(itr.first, width, seperator);
		print("||", div_width, seperator);
		print(itr.second, numWidth, seperator);
		print("||", div_width, seperator);
		if (itr.second == 0)
			print("(LOW)", 6, seperator);
		cout << endl;
	}
	cout << endl;
}

void DisplayBeverage(map<string, Beverage> beverages) {
	for (auto it:beverages) {
		cout << it.second.getName() << " :" << endl;
		map<string, int> requiredIngredients = it.second.getIngredients();
		for (auto ingredient_it:requiredIngredients) {
			cout << "     " << ingredient_it.first << " : " << ingredient_it.second << endl;
		}
		cout << endl;
	}
}

#endif // UTILS_H_INCLUDED
