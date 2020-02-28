// John Le
// 036123131
// OOP244 Assignment 2
// Crop.cpp

class Crop{
	Plant plant;
	int length;
	int width;
	int xcord;
	int ycord;
public:
	Crop();
	Crop(const Plant&, int, int, int, int);
	bool isEmpty()const;
	void display(std::ostream &)const;
	bool read(const Plant&);
	bool place(char * map, int, int)const;
	
};

std::ostream& operator<<(std::ostream&, const Crop&);