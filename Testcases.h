#ifndef TESTCASES_H_INCLUDED
#define TESTCASES_H_INCLUDED

#include<cassert>
#include <iostream>
#include "machine.h"
#include "Utils.h"
#include "ThreadPool.h"
using namespace std;

void TestRefill(Machine& machine) {
    cout << "Testing Refilling the machine" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventory(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("coffeeSyrup",20) }));
	cout << "Ingredients after refill : " << endl;
	DisplayInventory(machine);
}

void TestSuccessfulDispension(Machine& machine, int numThreads) {
    cout << "Testing serving a single beverage" << endl;
    cout << "Ingredients before serving : " << endl;
    DisplayInventory(machine);
    ThreadPool pool(numThreads, &machine);
    pool.submit("ginger_tea");
    pool.shutdown();
    cout << "Ingredients after serving : " << endl;
	DisplayInventory(machine);
}

void TestRefillMultiple(Machine& machine) {
    cout << "Testing Refilling the machine with multiple ingredients" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventory(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("hotWater",600),make_pair("hotMilk",100) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	cout << "Ingredients after refill : " << endl;
	DisplayInventory(machine);
}

void TestMultipleDispensions(Machine& machine, int numThreads) {
    cout << "Testing serving multiple beverages" << endl;
    cout << "Ingredients before serving : " << endl;
    DisplayInventory(machine);
    ThreadPool pool(numThreads, &machine);
    pool.submit("hot_tea");
    pool.submit("hot_coffee");
    pool.submit("green_tea");
    pool.submit("black_tea");
    pool.shutdown();
	cout << "Ingredients after serving : " << endl;
	DisplayInventory(machine);
}

void TestInsufficientIngredientQuantity(Machine& machine, int numThreads) {
    cout << "Testing serving a single beverage with insufficient quantity" << endl;
    ThreadPool pool(numThreads, &machine);
    pool.submit("espresso");
	DisplayInventory(machine);
}

void TestIngredientNotAvailable(Machine& machine, int numThreads) {
    cout << "Testing serving a single beverage with unavailable ingredient" << endl;
    ThreadPool pool(numThreads, &machine);
    pool.submit("green_tea");
    pool.shutdown();
	DisplayInventory(machine);
}

void TestRefillNewIngredient(Machine& machine) {
    cout << "Testing Refilling the machine with new ingredient" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventory(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("greenMixture",40) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	cout << "Ingredients after refill : " << endl;
	DisplayInventory(machine);
}


#endif // TESTCASES_H_INCLUDED
