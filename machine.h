#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include<string>
#include<map>
#include<vector>
#include<mutex>
using namespace std;

#include "Beverage.h"
#include "Utils.h"

class Machine{
	int numOutlets;
	map<string, int> availableIngredients;
	map<string, Beverage> beveragesList;
	mutex mu;

public:
	Machine(int _numOutlets, map<string, int> _availableIngredients, map<string, Beverage> _beveragesList){
		this->numOutlets = _numOutlets;
		this->availableIngredients = _availableIngredients;
		this->beveragesList = _beveragesList;
	}

	map<string, int> getAvailableIngredients(){
		unique_lock<mutex> lock(mu);
		return this->availableIngredients;
	}

	map<string, Beverage> getBeveragesList(){
		return this->beveragesList;
	}

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

	void serveBeverage(string beverage){
		unique_lock<mutex> lock(mu);
		if(beveragesList.find(beverage) == beveragesList.end()){
			return;
		}
		else{
            UpdateIngredientsAfterServing(beveragesList[beverage]);
		}
	}

	void UpdateIngredientsAfterServing(Beverage beverage){
		bool allIngredientsAvailable = true;
		map<string, int> requiredIngredients = beverage.getIngredients();
		for(auto ingredient:requiredIngredients){
			if(availableIngredients.find(ingredient.first) == availableIngredients.end()){
				cout << beverage.getName() << " cannot be prepared because "<< ingredient.first << " is not available" <<endl;
				allIngredientsAvailable = false;
				break;
			}
			if(ingredient.second > availableIngredients[ingredient.first]){
				cout << beverage.getName() << " cannot be prepared because "<< ingredient.first << " is not sufficient" <<endl;
				allIngredientsAvailable = false;
				break;
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
