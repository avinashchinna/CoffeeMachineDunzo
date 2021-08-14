#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include<string>
using namespace std;

//Helper Class for ingredient information.
class Ingredient {
	string name;
	int quantity;
public:
	Ingredient(string name, int quantity) {
		this->name = name;
		this->quantity = quantity;
	}
	string getName() {
		return name;
	}
	int getQuantity() {
		return quantity;
	}
	void setQuantity(int _quantity){
		this->quantity = _quantity;
	}
};


#endif // INGREDIENT_H_INCLUDED
