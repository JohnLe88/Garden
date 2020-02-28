
class Garden{
	Crop crops[20];
	int cropInGar;
	char * size;
	int lengar;
	int widthgar;
public:
	Garden();
	Garden(int, int);
	Garden(const Garden&);
	Garden& operator=(const Garden&);
	~Garden();
	bool isEmpty()const;
	Garden& operator+=(const Crop&);
	void display(std::ostream&)const;
	void displayBord(std::ostream &) const;
	void displayGar(std::ostream &) const;
};

std::ostream& operator<<(std::ostream&, const Garden&);