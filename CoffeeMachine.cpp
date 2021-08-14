#include<iostream>
#include<vector>
#include <string>
using namespace std;

#include "RequestQueue.h"
#include "ThreadPool.h"
#include "machine.h"
#include "Ingredient.h"
#include "Beverage.h"
#include "Utils.h"
#include "Testcases.h"

int main(){
    map<string, int> availableIngredients;
    availableIngredients.insert(make_pair("hotWater", 500));
    availableIngredients.insert(make_pair("hotMilk", 500));
    availableIngredients.insert(make_pair("gingerSyrup", 100));
    availableIngredients.insert(make_pair("sugarSyrup", 100));
    availableIngredients.insert(make_pair("teaLeavesSyrup", 100));
    availableIngredients.insert(make_pair("coffeeSyrup", 30));
    availableIngredients.insert(make_pair("elaichiSyrup", 100));

    map<string, Beverage> beverages;
    beverages.insert(make_pair("ginger_tea", Beverage("ginger_tea", map<string, int>{make_pair("hotWater", 500), make_pair("hotMilk", 100), make_pair("gingerSyrup", 40), make_pair("sugarSyrup", 30), make_pair("teaLeavesSyrup", 10)})));
    beverages.insert(make_pair("hot_tea", Beverage("hot_tea", map<string, int>{make_pair("hotWater", 200), make_pair("hotMilk", 100), make_pair("gingerSyrup", 10), make_pair("sugarSyrup", 10), make_pair("teaLeavesSyrup", 10)})));
    beverages.insert(make_pair("elaichi_tea", Beverage("elaichi_tea", map<string, int>{make_pair("hotWater", 200), make_pair("hotMilk", 100), make_pair("elaichiSyrup", 60), make_pair("sugarSyrup", 10), make_pair("teaLeavesSyrup", 10)})));
    beverages.insert(make_pair("hot_coffee", Beverage("hot_coffee", map<string, int>{make_pair("hotWater", 100), make_pair("hotMilk", 400), make_pair("sugarSyrup", 50), make_pair("coffeeSyrup", 20)})));
    beverages.insert(make_pair("espresso", Beverage("espresso", map<string, int>{make_pair("hotWater", 200), make_pair("coffeeSyrup", 40)})));
    beverages.insert(make_pair("black_tea", Beverage("black_tea", map<string, int>{make_pair("hotWater", 300), make_pair("gingerSyrup", 30), make_pair("sugarSyrup", 50), make_pair("teaLeavesSyrup", 30)})));
    beverages.insert(make_pair("hot_milk", Beverage("hot_milk", map<string, int>{make_pair("hotMilk", 200), make_pair("sugarSyrup", 30)})));
    beverages.insert(make_pair("green_tea", Beverage("green_tea", map<string, int>{make_pair("hotWater", 100), make_pair("gingerSyrup", 30), make_pair("greenMixture", 30)})));

    Machine machine(3, availableIngredients, beverages);
    DisplayBeverage(beverages);
    DisplayInventory(machine);

    //TestSuite
    TestInsufficientIngredientQuantity(machine, 3);
    TestRefill(machine);
    TestSuccessfulDispension(machine, 3);
    TestRefillMultiple(machine);
    TestMultipleDispensions(machine, 2);
    TestIngredientNotAvailable(machine, 4);
    TestRefillNewIngredient(machine);
    TestIngredientNotAvailable(machine, 2);

    return 0;
}
