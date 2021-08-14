#include "fileIO.h"

void writeFile(str& fName, bool startChoice, bool qChoice)
{
	std::ofstream file;
	file.open(fName, std::ios_base::out);
	file << startChoice << std::endl;
	file << qChoice << std::endl;
}

bool readFile(str& fName, bool *normCl)
{
	bool stC = false;
	str validation = "";

	std::ifstream file;
	file.open(fName);
	if (!file)
	{
		std::ofstream f;
		f.open(fName, std::ios_base::out);
		f.close();
	}
	char i = 0;
	while (getline(file, validation))
	{
		if(validation == "")
			continue;
		else if (isspace(validation))
			continue;
		else if (validation.length() == 1 && validation.at(0) >= '0' && validation.at(0) <= '9')
		{
			if (i == 0)
				stC = (validation.at(0) - '0');
			else if (i == 1)
				*normCl = (validation.at(0) - '0');
			i++;
		}
		else
		{
			prl("\nError reading setting file\n");
			return false;
		}
	}
	file.close();
	return stC;
}

bool isspace(str wtf)
{
	const char* c = wtf.c_str();
	for (int i = 0; i < wtf.length(); i++)
	{
		if (isspace(*c++))
			return true;
	}
	return false;
}
