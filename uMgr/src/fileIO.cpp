#include "fileIO.h"

bool isspace(str& s)
{
	const char* c = s.c_str(); // i will probable never use multibyte char for this
	for (int i = 0; i < s.length(); i++)
	{
		if (isspace(*c++))
			return true;
	}
	return false;
}
