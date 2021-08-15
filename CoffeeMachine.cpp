#include<iostream>
#include<vector>
#include <string>
using namespace std;

#include "Utils.h"
#include "RequestQueue.h"
#include "ThreadPool.h"
#include "machine.h"
#include "Ingredient.h"
#include "Beverage.h"
#include "Testcases.h"

int main(){
    // list of ingredients needed for the beverages
    map<string, int> availableIngredients;
    availableIngredients.insert(make_pair("hotWater", 500));
    availableIngredients.insert(make_pair("hotMilk", 500));
    availableIngredients.insert(make_pair("teaLeavesSyrup", 100));
    availableIngredients.insert(make_pair("gingerSyrup", 20));
    availableIngredients.insert(make_pair("sugarSyrup", 100));
    availableIngredients.insert(make_pair("elaichiSyrup", 100));
    availableIngredients.insert(make_pair("coffeeSyrup", 20));

    // list of beverages to be served by the machine and their required ingredients in respective quantities
    map<string, Beverage> beverages;
    beverages.insert(make_pair("ginger_tea", Beverage("ginger_tea", map<string, int>{make_pair("hotWater", 50), make_pair("hotMilk", 10), make_pair("teaLeavesSyrup", 10), make_pair("gingerSyrup", 20), make_pair("sugarSyrup", 10)})));
    beverages.insert(make_pair("elaichi_tea", Beverage("elaichi_tea", map<string, int>{make_pair("hotWater", 50), make_pair("hotMilk", 10), make_pair("teaLeavesSyrup", 10), make_pair("elaichiSyrup", 5), make_pair("sugarSyrup", 10)})));
    beverages.insert(make_pair("hot_coffee", Beverage("hot_coffee", map<string, int>{make_pair("hotWater", 50), make_pair("hotMilk", 10), make_pair("coffeeSyrup", 10), make_pair("sugarSyrup", 10)})));
    beverages.insert(make_pair("hot_tea", Beverage("hot_tea", map<string, int>{make_pair("hotWater", 200), make_pair("hotMilk", 100), make_pair("teaLeavesSyrup", 30), make_pair("sugarSyrup", 10), make_pair("gingerSyrup", 10)})));
    beverages.insert(make_pair("hot_milk", Beverage("hot_milk", map<string, int>{make_pair("hotMilk", 50)})));
    beverages.insert(make_pair("hot_water", Beverage("hot_water", map<string, int>{make_pair("hotWater", 50)})));
    beverages.insert(make_pair("green_tea", Beverage("green_tea", map<string, int>{make_pair("hotWater", 100), make_pair("gingerSyrup", 20), make_pair("green_mixture", 30), make_pair("sugarSyrup", 50)})));
    beverages.insert(make_pair("black_tea", Beverage("black_tea", map<string, int>{make_pair("hotWater", 300), make_pair("teaLeavesSyrup", 30), make_pair("sugarSyrup", 50), make_pair("gingerSyrup", 50)})));

    //machine object with 3 outlets to serve beverages
    Machine machine(3, availableIngredients, beverages);
    machine.DisplayInventory();

    //TestCases
    TestIngredientQuantities(machine);
    TestRefill(machine);
    TestServing(machine);
    TestRefillMultiple(machine);
    TestServeMultiple(machine);
    TestIngredientAvailability(machine);
    TestRefillNew(machine);

    return 0;
}
