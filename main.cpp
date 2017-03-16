#include <iostream>
#include <fstream>
#include <iomanip>
/*****************************************************************************************/
#define VALUE_PRECISION 10
#define VALUE_FILL 10
/*****************************************************************************************/
int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	long double X, Y, Z, rX, rY, rZ;

	std::cout << std::setprecision(VALUE_PRECISION) << std::setw(VALUE_FILL);
	std::cin >> std::setprecision(VALUE_PRECISION);

	std::cout << "Enter the correction factor X: ";
	std::cin >> X;
	std::cout << "Enter the correction factor Y: ";
	std::cin >> Y;
	std::cout << "Enter the correction factor Z: ";
	std::cin >> Z;
	std::cout << "Enter the correction factor rX: ";
	std::cin >> rX;
	std::cout << "Enter the correction factor rY: ";
	std::cin >> rY;
	std::cout << "Enter the correction factor rZ: ";
	std::cin >> rZ;
	std::cout << "Correction Terms: " << X << " " << Y << " " << Z << " "<< rX << " " << rY << " " << rZ << std::endl << std::endl;

	inputFile.open("input.pwn");
	outputFile.open("output.pwn");

	if (!inputFile) std::cout << "Failed to open \"input.pwn\"."<<std::endl;
	if (!outputFile) std::cout << "Failed to create \"output.pwn\"." << std::endl;
	
	if (inputFile && outputFile)
	{
		char text[64];
		long double value;

		outputFile << std::setprecision(VALUE_PRECISION) << std::setw(VALUE_FILL);
		inputFile >> std::setprecision(VALUE_PRECISION);

		while (!inputFile.eof())
		{
			inputFile >> text; 
			if (text[0] == '\0' || (text[0] == '\r' && text[1] == '\0')) break;

			std::cout << text;
			outputFile << text; //CreateObject(modelid,			

			inputFile >> value;
			inputFile.ignore(1, ',');
			std::cout << (value + X) << ", ";
			outputFile << (value + X) << ", "; //x

			inputFile >> value;
			inputFile.ignore(1, ',');
			std::cout << (value + Y) << ", ";
			outputFile << (value + Y) << ", "; //y

			inputFile >> value;
			inputFile.ignore(1, ',');
			std::cout << (value + Z) << ", ";
			outputFile << (value + Z) << ", "; //z

			inputFile >> value;
			inputFile.ignore(1, ',');
			std::cout << (value + rX) << ", ";
			outputFile << (value + rX) << ", "; //rx

			inputFile >> value;
			inputFile.ignore(1, ',');
			std::cout << (value + rY) << ", ";
			outputFile << (value + rY) << ", "; //ry

			inputFile >> value;
			inputFile.ignore(1, ')');
			inputFile.ignore(1, ';');
			std::cout << (value + rZ) << ");" << std::endl;
			outputFile << (value + rZ) << ");" <<std::endl; //rz
		}
	}

	std::cout << "Press any key to close the program.";
	std::cin.ignore();
	return 0;
}

