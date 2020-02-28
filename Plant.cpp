// John Le
// 036123131
// OOP244 Assignment 2
// Plant.cpp
#include <iostream>
#include "Plant.h"


using namespace std;

Plant::Plant(){
	//Constructor for Plant
	name[0] = '\0';
	sym = '\0';
}

Plant::Plant(const char* n, char s){
	//Validates the incoming values and sets them if it passes, if not sets to safe empty state
	if (n != nullptr && s != '\0' && (strlen(n) <= 20)){
		strcpy(name, n);
		sym = s;
	}
	else{
		*this = Plant();
	}

	if (n == ""){
		*this = Plant();
	}
}

bool Plant::isEmpty()const{
	//Checks if object is empty
	if (name[0] != '\0' && sym != '\0'){
		return false;
	}
	else
		return true;
}

void Plant::display(std::ostream &os)const{
	//Display that shows the symbol used and plant name
	if (name[0] != '\0'){
		os << symbol() << " = " << plantName() << endl;
	}

}

bool Plant::read(){
	//Reads in the input from users and checks to see if valid, if valid values are
	//copied over and loops end
	char plantcheck[20];
	char inital;
	bool check = false;
	do{
		cout << "Enter Plants Name : ";
		cin.getline(plantcheck, 20, '\n');
		cout << "Enter first letter of plants name: ";
		cin >> inital;
		if (plantcheck == '\0' || inital == '\0'){
			cin.clear();
			cin.ignore(2000, '\n');
			cerr << "Error, try again. " << endl;
			return false;
		}
		else{
			strcpy(name, plantcheck);
			sym = inital;
			check = true;
			return true;
		}
	} while (check = false);
	
}


std::ostream& operator<<(std::ostream& os, const Plant& src){
	//Custom operator for output
	src.display(os);
	return os;
}

bool operator==(const Plant& lft, const Plant& rgt){
	//checks to see if both plants are the same
	if (strcmp(lft.plantName(), rgt.plantName())==0 && lft.symbol() == rgt.symbol()){
			return true;
	}
	else
		return false;
}