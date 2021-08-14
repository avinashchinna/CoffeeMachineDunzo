#ifndef BEVERAGE_H_INCLUDED
#define BEVERAGE_H_INCLUDED

#include<string>
#include<map>
using namespace std;

#include "Ingredient.h"

class Beverage{
	string name;
	map<string, int> requiredIngredients;
public:
	Beverage(){}

	Beverage(string _name, map<string, int> ingredients){
		this->name = _name;
		this->requiredIngredients = ingredients;
	}
	string getName(){
		return this->name;
	}
	map<string, int> getIngredients(){
		return this->requiredIngredients;
	}
};

#endif // BEVERAGE_H_INCLUDED
