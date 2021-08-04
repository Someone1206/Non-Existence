#include "fileIO.h"

void writeFile(str& fName, bool choice)
{
	std::ofstream file;
	file.open(fName, std::ios_base::out);
	file << choice;
}

bool readFile(str& fName)
{
	bool stC = false;
	str validation = "";

	std::ifstream file;
	file.open(fName);
	if (!file)
	{
		std::ofstream f;
		f.open(fName, std::ios_base::out);
		file >> stC;
		f.close();
	}
	
	file >> validation;
	if (validation == "")
		return false;
	if (validation.length() == 1 && validation.at(0) >= '0' && validation.at(0) <= '9')
		return (validation.at(0) - '0' == 0 ? false : true);
	else {
		prl("\nError reading setting file\n");
		return false;
	}
	file.close();
	return false;
}
