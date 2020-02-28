#include <iostream>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"

using namespace std;

Garden::Garden(){
	//Garden Constructor
	cropInGar = 0;
	size = nullptr;
	lengar = 0;
	widthgar = 0;
}
Garden::Garden(int a, int b){
	//Function that takes in 2 int for the size of garden and gets validated, if pass
	//the garden is made
	if (a > 0 && b > 0){
		
		lengar = a;
		widthgar = b;
		
		size = new char[a*b];
		for (int i = 0; i < a*b; i++){
			size[i] = ' ';
		}
	}
	else{
		lengar = 0;
		widthgar = 0;
		
	}
}

Garden::Garden(const Garden& source){
	//Part of copy constructor
	size = nullptr;
	*this = source;
}

Garden& Garden::operator=(const Garden& src){
	//Copy costructor that does a deep copy and deletes shallow copy
	if (this != &src){
		cropInGar = src.cropInGar;
		lengar = src.lengar;
		widthgar = src.widthgar;
		for (int i = 0; i < src.cropInGar; i++){
			crops[i] = src.crops[i];
		}
		delete[] size;
		if (src.size != nullptr){
			size = new char[src.lengar * src.widthgar];
			//strcpy(size, src.size);
			for (int i = 0; i < src.lengar * src.widthgar; i++){
				size[i] = src.size[i];
			}
			
		}
		else{
			size = nullptr;
		}
	}
	
	return *this;
}

Garden::~Garden(){
	//Deconstructor
	size = nullptr;
	delete[] size;
}

bool Garden::isEmpty()const{
	//Checks if Garden is empty
	if (size != nullptr && lengar > 0){
		return false;
	}
	else
		return true;
}

Garden& Garden::operator+=(const Crop& cro){
	//Operator that checks if there is room in the garden, if so crop is added into garden
	if (cropInGar < 20){
		crops[cropInGar] = cro;
		cro.place(size, lengar, widthgar);
		cropInGar += 1;
	}
	else{
		std::cout << "No more room for crop." << std::endl;
	}
	return *this;
}

void Garden::display(std::ostream& os)const{
	//Simple display function with 2 different other displays to keep it tidy and clean.
	//This displays the garden
	if (size != nullptr){
		displayBord(os);
		displayGar(os);
		displayBord(os);
	}
	
	
}

std::ostream& operator<<(std::ostream& os, const Garden& src){
	//Custom output operator
	src.display(os);
	return os;
}

void Garden::displayBord(std::ostream & os) const{
	//Displays the top and bottom border
	os << "+";
	for (int x = 0; x < widthgar; x++){
		os << "-";
	}
	os << "+\n";
}

void Garden::displayGar(std::ostream & os) const{
	//Displays the inside of garden
	int si = 0;
	for (int i = 0; i < lengar; i++){
		os << "|";
		for (int j = 0; j < widthgar; j++){
			os << size[si++];
		}
		os << "|" << endl;
	}

}