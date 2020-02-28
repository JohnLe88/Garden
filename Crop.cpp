// John Le
// 036123131
// OOP244 Assignment 2
// Crop.cpp
#include <iostream>
#include "Map.h"
#include "Plant.h"
#include "Crop.h"



using namespace std;

Crop::Crop(){
	//Constructor for Crops
	length = 0;
	width = 0;
	xcord = 0;
	ycord = 0;

}

Crop::Crop(const Plant& source, int len, int wid, int xx, int yy){
	//Function that takes in input and validates them, if pass values will be copied over
	if (len > 0 && len <= MAPL && wid > 0 && wid <= MAPW && xx <= MAPL || xx <= MAPW && yy <= MAPL || yy <= MAPW){
		plant = source;
		length = len;
		width = wid;
		xcord = xx;
		ycord = yy;
	}

	else
		*this = Crop();
		
}

bool Crop::isEmpty()const{
	//Checks if current Crop is empty
	if (plant.isEmpty()){
		return true;
	
	}
	else{
		return false;
	}
}

void Crop::display(std::ostream &os)const{
	//Displays the size of plant with plants name
	if (!plant.isEmpty()){

		for (int i = 0; i < length; i++){
			for (int x = 0; x < width; x++){
				os << plant.symbol();

			}

			os << endl;
		}
		plant.display(os);
	}
}

bool Crop::read(const Plant& src){
	//Reads the users input and validates them, if values are true it copies over value
	int templen;
	int tempwid;
	int tempx;
	int tempy;
	bool check = false;
	do{
		cout << "Enter Length: ";
		cin >> templen;
		cout << "Enter Width: ";
		cin >> tempwid;
		cout << "Enter in x coordinates: ";
		cin >> tempx;
		cout << "Enter in y coordinates: ";
		cin >> tempy;

		if (templen < 0 && tempwid < 0 && tempy > MAPL && tempx > MAPW){
			cout << "You entered invalid number" << endl;
			return false;
		}
		else{
			plant = src;
			length = templen;
			width = tempwid;
			xcord = tempx;
			ycord = tempy;
			check = true;
		}
	} while (check = false);
	
}

bool Crop::place(char * map, int mapleng/*y*/, int mapwidth /*x*/)const{
	//Main member function that checks if plant is not empty and values passed to it are
	//valid to place the crop in garden
	if (!plant.isEmpty() && map != nullptr && mapleng >= 0 && mapwidth >=0){
		
		for (int i = 0; i < length; i++){
			for (int x = 0; x < width; x++){		
				map[(ycord + i) * mapwidth + (xcord + x)] = plant.symbol();	
			}
		}
		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Crop& src){
	//Custom operator for display
	src.display(os);
	return os;
}