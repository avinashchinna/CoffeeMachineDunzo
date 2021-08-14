#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "machine.h"
#include<iomanip>
using namespace std;

void DisplayInventoryUtil(Machine& machine) {
	machine.DisplayInventory();
	cout << endl;
}

#endif // UTILS_H_INCLUDED
