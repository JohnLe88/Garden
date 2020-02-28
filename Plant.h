// John Le
// 036123131
// OOP244 Assignment 2
// Plant.h

class Plant{
	char name[20];
	char sym;
public:
	Plant();
	Plant(const char*, char);
	bool isEmpty()const;
	char symbol()const{ return sym; };
	void display(std::ostream &)const;
	bool read();
	const char* plantName()const{ return name; };
	
};

std::ostream& operator<<(std::ostream&, const Plant&);

bool operator==(const Plant&, const Plant&);