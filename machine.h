#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include "Beverage.h"

#include<string>
#include<map>
#include<vector>
#include<mutex>
#include<iomanip>
using namespace std;

//Template function to print the inventory details to stdout
template<typename T> void print(T t, const int& width, const char& seperator)
{
	cout << left << setw(width) << setfill(seperator) << t;
}

//class container to store information about Machine
class Machine{
	int numOutlets;
	map<string, int> availableIngredients; //stores the quantity of Ingredients present in the machine
	map<string, Beverage> beveragesList; // stores the mapping between beverage name to Beverage class
	mutex mu; //mutex to provide access to shared data structures between concurrent threads

public:
	Machine(int _numOutlets, map<string, int> _availableIngredients, map<string, Beverage> _beveragesList){
		this->numOutlets = _numOutlets;
		this->availableIngredients = _availableIngredients;
		this->beveragesList = _beveragesList;
	}

    int getNumOutlets(){
        return this->numOutlets;
    }

	map<string, int> getAvailableIngredients(){
		unique_lock<mutex> lock(mu);
		return this->availableIngredients;
	}

	map<string, Beverage> getBeveragesList(){
		return this->beveragesList;
	}

    //Helper function to print the inventory details to stdout in a defined way
    void DisplayInventory(){
        const int width = 20;
        const int numWidth = 9;
        const int div_width = 4;
        const char seperator = ' ';
        for (auto itr:availableIngredients) {
            print("#", div_width, seperator);
            print(itr.first, width, seperator);
            print("#", div_width, seperator);
            print(itr.second, numWidth, seperator);
            print("#", div_width, seperator);
            if (itr.second == 0)
                print("(LOW on Quantity)", 6, seperator);
            cout << endl;
        }
        cout << endl;
    }

    //Helper function to fill the ingredients in the machine
	void RefillIngredients(map<string, int> ingredients){
		unique_lock<mutex> lock(mu);
		for(auto ingredient:ingredients){
			if(availableIngredients.find(ingredient.first) == availableIngredients.end()){
				availableIngredients.insert(make_pair(ingredient.first, ingredient.second));
			}else{
				availableIngredients[ingredient.first] += ingredient.second;
			}
		}
	}

    //Helper function to serve beverage to customer
	void serveBeverage(string beverage){
		unique_lock<mutex> lock(mu);
		if(beveragesList.find(beverage) == beveragesList.end()){
			return;
		}
		else{
            cout << "Ingredients before serving " << beverage << endl;
            DisplayInventory();
            UpdateIngredientsAfterServing(beveragesList[beverage]);
		}
	}

	//Check the availability of all required ingredients for a beverage and update the quantity of ingredients in the machine
	void UpdateIngredientsAfterServing(Beverage beverage){
		bool allIngredientsAvailable = true;
		map<string, int> requiredIngredients = beverage.getIngredients();
		for(auto ingredient:requiredIngredients){
			if(availableIngredients.find(ingredient.first) == availableIngredients.end()){
				cout << beverage.getName() << " cannot be prepared because "<< ingredient.first << " is not available" <<endl;
				allIngredientsAvailable = false;
				break;
			}
		}

		if(allIngredientsAvailable){
            for(auto ingredient:requiredIngredients){
                if(ingredient.second > availableIngredients[ingredient.first]){
                    cout << beverage.getName() << " cannot be prepared because "<< ingredient.first << " is not sufficient" <<endl;
                    allIngredientsAvailable = false;
                    break;
                }
            }
		}

		if(allIngredientsAvailable){
			for(auto ingredient:requiredIngredients){
				availableIngredients[ingredient.first] -= ingredient.second;
			}
			cout << beverage.getName() << " is prepared" << endl;
		}
	}

};

#endif // MACHINE_H_INCLUDED
