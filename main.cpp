#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

const int value_precision = 10;
const int value_width = 10;

struct Object {
	typedef long double float_t;
	int modelid;
	std::string func;
	std::string extra;
	float_t X, Y, Z;
	float_t rX, rY, rZ;	
};
std::istream &operator >> (std::istream &is, Object &obj) {	
	std::getline(is, obj.func, '('); obj.func += '(';
	
	is >> obj.modelid;
	is.ignore(1, ',');

	is >> obj.X;
	is.ignore(1, ',');

	is >> obj.Y;
	is.ignore(1, ',');

	is >> obj.Z;
	is.ignore(1, ',');

	is >> obj.rX;
	is.ignore(1, ',');

	is >> obj.rY;
	is.ignore(1, ',');

	is >> obj.rZ;

	std::getline(is, obj.extra, ')');
	is.ignore(1, ';');
	is.ignore(1, '\n');
	return is;
}
std::ostream &operator << (std::ostream &is, Object &obj) {
	is << obj.func << obj.modelid << ", ";
	is << obj.X << ", " << obj.Y << ", " << obj.Z << ", ";
	is << obj.rX << ", " << obj.rY << ", " << obj.rZ << obj.extra << ");";
	return is;
}

int main() {
	std::cin >> std::setprecision(value_precision);

	long double cX, cY, cZ, crX, crY, crZ;
	std::cout << "Enter the position correction factor (X, Y, Z): ";
	std::cin >> cX >> cY >> cZ;
	std::cout << "Enter the rotation correction factor (rX, rY, rZ): ";
	std::cin >> crX >> crY >> crZ;

	std::ifstream inputFile("input.pwn");
	if (!inputFile) {
		std::cout << "Failed to open \"input.pwn\".";
		return  0;
	}

	std::ofstream outputFile("output.pwn");
	if (!outputFile) {
		std::cout << "Failed to create \"output.pwn\".";
		return 0;
	}

	std::cout << std::setprecision(value_precision) << std::setw(value_width);
	outputFile << std::setprecision(value_precision) << std::setw(value_width);
	inputFile >> std::setprecision(value_precision);

	Object obj;
	while(inputFile >> obj) {
		obj.X += cX;
		obj.Y += cY;
		obj.Z += cZ;
		obj.rX += crX;
		obj.rY += crY;
		obj.rZ += crZ;

		std::cout << obj << '\n';
		outputFile << obj << '\n';
	}
	return 0;
}

