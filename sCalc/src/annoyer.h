#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define pr(wtf) cout << wtf
#define prl(wtf) cout << wtf << endl

bool RUN = true;

string ip = "", m = "(cmd)", pm = "==>   ";

bool ckd(char& c, bool ck = false, bool r = false, bool is_p = false, bool is_ve = false)
{
	bool omg = true;
	if (ck)
	{
		if (c == '+' || c == '-')
		{
			if (is_p)
			{
				return (c == '+') ? true : false;
			}
			else if (is_ve)
			{
				return (c == '-') ? true : false;
			}
			return true;
		}
		else if (r) {
			omg = false;
		}
	}

	for (char i = '0'; i <= '9'; i++)
	{
		if (c == i)
		{
			return true;
		}
	}
	if (r)
	{
		return omg;
	}
	return false;
}

bool validex(string& exp)
{
	bool valid = false, indec = true;
	int8_t count = 0;
	char c, cn, cp;
	unsigned int len = exp.length();
	for (unsigned int i = 0; i < len; ++i)
	{
		c = exp.at(i);
		if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
		{
			pr(c);
			prl(" or any other form of brackets not supported because why tf not?");
			return false;
		}
		if (ckd(c, true) || c == '*' || c == '/' || c == '\\' || c == '.')
		{
			if (i < 1)
			{
				cp = exp.at(i);
				if (len > 1)
				{
					cn = exp.at(i + 1);
				}
			}
			else if (i == (len - 1))
			{
				cp = exp.at(i - 1);
				cn = exp.at(i);
			}
			else
			{
				cp = exp.at(i - 1);
				cn = exp.at(i + 1);
			}
			if (c == '+' || c == '-')
			{
				count = 0;
				valid = true;
				continue;
			}
			if (c == '-')
			{
				if (exp.at(i) == '+')
				{
					return false;
				}
			}
			else if (c == '*' || c == '/' || c == '\\')
			{
				count = 0;
				if (ckd(cn, true, true) && ckd(cp))
				{
					valid = true;
				}
				else
					return false;
			}
			if (c == '.')
			{
				count++;
			}
			if (count > 1)
			{
				return false;
			}
			valid = true;
		}
		else
			return false;
	}

	if (exp.at(len - 1) == '+' || exp.at(len - 1) == '-')
		return false;
	
	return valid;
}