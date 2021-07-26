#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define pr(wtf) cout << wtf
#define prl(wtf) cout << wtf << endl

bool RUN = true;

string ip = "", m = "(cmd)", pm = "==>   ";

int index = 0, len = 0;

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

void expForm(string& exp)
{
	unsigned short count = 0;
	bool plus = false, minus = false;
	char c;
	string r = "";
	for (unsigned int i = 0; i < exp.length(); ++i)
	{
		c = exp.at(i);
		if (c == '+')
		{
			if (!plus)
			{
				r += c;
			}
			plus = true;
		}
		else {
			plus = false;
		}
		if (c == '-')
		{
			minus = true;
			count++;
		}
		else {
			if (minus)
			{
				r += (count % 2 == 0) ? '+' : '-';
				count = 0;
			}
			minus = false;
		}
		if (c != '+' && c != '-') {
			r += c;
		}
	}
	exp = r;
}

// couldn't do without functions...

char now(string& exp)
{
	if (index >= len) {
		return 'E'; // ;)
	}
	return exp.at(index);
}

char nxt(string& exp)
{
	if (index >= len) {
		return 'E'; // :)
	}
	return exp.at(index++);
}

double long expr(string& exp);

double long toNum(string& exp)
{
	double long res = nxt(exp) - '0';
	bool is_dec = false;
	int8_t count = 1;

	while ((now(exp) >= '0' && now(exp) <= '9' && now(exp) != ' ') || now(exp) == '.') {
		if (now(exp) == '.')
		{
			is_dec = true;
			index++;
		}
		if (is_dec)
		{
			res = res + ((nxt(exp) - '0') / pow((int8_t)10, count));
			count++;
			continue;
		}
		res = 10 * res + (nxt(exp) - '0');
	}

	return res;
}

double long term(string& exp)
{
	if ((now(exp) >= '0' && now(exp) <= '9') || now(exp) == '.')
		return toNum(exp);
	else if (now(exp) == '-') {
		index++;
		return -term(exp);
	}
	else if (now(exp) == '+')
	{
		index++;
		return toNum(exp);
	}
	return -0x45; // err :)
}

double long mdr(string& exp)
{
	double long res = term(exp);

	while (now(exp) == '*' || now(exp) == '/' || now(exp) == '\\')
		if (nxt(exp) == '*')
			res *= term(exp);
		else
			res /= term(exp);
	return res;
}

double long expr(string& exp)
{
	expForm(exp);
	index = 0;
	len = exp.length();

	double long res = mdr(exp);

	while (now(exp) == '+' || now(exp) == '-') {
		if (nxt(exp) == '+')
			res += mdr(exp);
		else
			res -= mdr(exp);
	}
	return res;
}
