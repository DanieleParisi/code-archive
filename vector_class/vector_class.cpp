#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

struct Vector{
	Vector() : x(0), y(0) { };
	Vector(int a, int b) : x(a), y(b) { }
	friend Vector operator+(const Vector, const Vector);
	friend std::istream& operator>>(std::istream&, Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	double length() const { return sqrt(pow(x,2) + pow(y,2)); }
	
private:
	int x;
	int y;
};

Vector operator+(const Vector a,const Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	out << "(" << vec.x << "," << vec.y << ")"; 
	return out;
}

bool operator==(const Vector& a, const Vector& b) {
	return a.length() == b.length();
}

bool operator!=(const Vector& a, const Vector& b) {
	return !(a.length() == b.length());
}

std::istream& operator>>(std::istream& i, Vector& vec) {
	std::string temp;
	i >> temp;
	try {
		auto comma = temp.find_first_of(',');
		if (comma == temp.npos)
			throw(std::invalid_argument(""));
		int x = std::stoi(std::string(temp.begin(),temp.begin() + comma));
		int y = std::stoi(std::string(temp.begin() + comma + 1,temp.end()));
		vec.x = x;
		vec.y = y;
	} catch (std::invalid_argument &c) {
		i.setstate(i.failbit);
	}
	if (!i) {
		std::cerr << "Input error";
		vec = Vector();
	}
	return i;
}



main() {
	Vector a(1,2);
	Vector b(31,2);
	std::cout << (a != b);
	
}
	

