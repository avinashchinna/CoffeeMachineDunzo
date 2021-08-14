#ifndef TESTCASES_H_INCLUDED
#define TESTCASES_H_INCLUDED

#include "machine.h"
#include<cassert>
#include <iostream>
#include "utils.h"
using namespace std;

void TestRefill(Machine& machine) {
	machine.RefillIngredients(map<string, int>({ make_pair("coffeeSyrup",20) }));
	assert(machine.getAvailableIngredients()["coffeeSyrup"] == 50);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestSuccessfulDispension(Machine & machine) {
	machine.serveBeverage("ginger_tea");
	map<string, int> ingredients = machine.getAvailableIngredients();
	assert(ingredients["hotWater"] == 0);
	assert(ingredients["hotMilk"] == 400);
	assert(ingredients["gingerSyrup"] == 60);
	assert(ingredients["sugarSyrup"] == 70);
	assert(ingredients["teaLeavesSyrup"] == 90);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestRefillMultiple(Machine & machine) {
	machine.RefillIngredients(map<string, int>({ make_pair("hotWater",600),make_pair("hotMilk",100) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	assert(ingredients["hotWater"] == 600);
	assert(ingredients["hotMilk"] == 500);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestMultipleDispensions(Machine & machine) {
	machine.serveBeverage("hot_tea");
	machine.serveBeverage("hot_coffee");
	machine.serveBeverage("green_tea");
	machine.serveBeverage("black_tea");
	map<string, int> ingredients = machine.getAvailableIngredients();
	assert(ingredients["hotWater"] == 300);
	assert(ingredients["hotMilk"] == 0);
	assert(ingredients["coffeeSyrup"] == 30);
	assert(ingredients["gingerSyrup"] == 50);
	assert(ingredients["sugarSyrup"] == 10);
	assert(ingredients["teaLeavesSyrup"] == 80);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestInsufficientIngredientQuantity(Machine& machine) {
	cout << " testing started " << endl;
	machine.serveBeverage("espresso");
	cout << " item served " << endl;
	map<string, int> ingredients = machine.getAvailableIngredients();
	assert(ingredients["coffeeSyrup"] == 30);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestIngredientNotAvailable(Machine& machine) {
	machine.serveBeverage("green_tea");
	cout << "PASS" << endl;
	DisplayInventory(machine);
}

void TestRefillNewIngredient(Machine& machine) {
	machine.RefillIngredients(map<string, int>({ make_pair("greenMixture",40) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	assert(ingredients["greenMixture"] == 40);
	cout << "PASS" << endl;
	DisplayInventory(machine);
}


#endif // TESTCASES_H_INCLUDED
