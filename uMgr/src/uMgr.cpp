#include "fileIO.h"

int main() {
	str name = folderN + fsep + "Settings.baka"; // :) use mah other product (scalc) to know the origin of the file extention
	str validation = "";

	fs::create_directory(folderN);
	fstream setFile;

	{
		ofstream f;
		if (!fs::exists(name))
		{
			f.open(name);
			f << 0;
			f.close();
		}
		
		if (!fs::exists((folderN + fsep + "LastLog.baka"))) // :)
		{
			f.open(folderN + fsep + "LastLog.baka");
			f.close();
		}
	}

	bool mkgenre = 0;
	setFile.open(name);

	while (getline(setFile, validation))
	{
		if (validation == "")
			continue;
		else if (isspace(validation))
			continue;
		else if (validation.length() == 1 && validation.at(0) >= '0' && validation.at(0) <= '9')
		{
			mkgenre = (validation.at(0) - '0');
		}
		else
		{
			prl("\nError reading setting file\n");
			return false;
		}
	}

	// creating some predefined genres cuz... fu, look at my README.md
	if (mkgenre == 0)
	{
		fs::create_directory(folderN + fsep + "Anime");
		fs::create_directory(folderN + fsep + "Manga");
		fs::create_directory(folderN + fsep + "Movies");
	}
	setFile.close();
}