#ifndef TESTCASES_H_INCLUDED
#define TESTCASES_H_INCLUDED

#include <iostream>
using namespace std;

#include "Utils.h"
#include "machine.h"
#include "ThreadPool.h"

void TestRefill(Machine& machine) {
    cout << "Testing Refilling the machine" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventoryUtil(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("coffeeSyrup",20) }));
	cout << "Ingredients after refill : " << endl;
	DisplayInventoryUtil(machine);
}

void TestServing(Machine& machine) {
    cout << "Testing serving a single beverage" << endl;
    int numThreads = machine.getNumOutlets();
    ThreadPool pool(numThreads, &machine);
    pool.submit("ginger_tea");
    pool.shutdown();
    cout << "Ingredients after serving : " << endl;
	DisplayInventoryUtil(machine);
}

void TestRefillMultiple(Machine& machine) {
    cout << "Testing Refilling the machine with multiple ingredients" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventoryUtil(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("hotWater",500),make_pair("hotMilk",500),make_pair("gingerSyrup", 40) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	cout << "Ingredients after refill : " << endl;
	DisplayInventoryUtil(machine);
}

void TestServeMultiple(Machine& machine) {
    cout << "Testing serving multiple beverages" << endl;
    int numThreads = machine.getNumOutlets();
    ThreadPool pool(numThreads, &machine);
    pool.submit("hot_tea");
    pool.submit("hot_coffee");
    pool.submit("green_tea");
    pool.submit("black_tea");
    pool.shutdown();
	cout << "Ingredients after serving : " << endl;
	DisplayInventoryUtil(machine);
}

void TestIngredientQuantities(Machine& machine) {
    cout << "Testing serving a single beverage with insufficient quantity" << endl;
    int numThreads = machine.getNumOutlets();
    ThreadPool pool(numThreads, &machine);
    pool.submit("black_tea");
    pool.shutdown();
	DisplayInventoryUtil(machine);
}

void TestIngredientAvailability(Machine& machine) {
    cout << "Testing serving a single beverage with unavailable ingredient" << endl;
    int numThreads = machine.getNumOutlets();
    ThreadPool pool(numThreads, &machine);
    pool.submit("green_tea");
    pool.shutdown();
	DisplayInventoryUtil(machine);
}

void TestRefillNew(Machine& machine) {
    cout << "Testing Refilling the machine with new ingredient" << endl;
    cout << "Ingredients before refill : " << endl;
    DisplayInventoryUtil(machine);
	machine.RefillIngredients(map<string, int>({ make_pair("green_mixture",100) }));
	map<string, int> ingredients = machine.getAvailableIngredients();
	cout << "Ingredients after refill : " << endl;
	DisplayInventoryUtil(machine);
}


#endif // TESTCASES_H_INCLUDED
