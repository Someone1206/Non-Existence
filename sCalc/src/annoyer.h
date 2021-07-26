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

int8_t h = 0, hc = 0;

void selft(int8_t mode)
{
	switch (mode)
	{
	case 1:					// cmd
		prl("\t(cmd)==>   /      s");
		prl("\t(calc)==>");
		prl("\t**next**");
		prl("\t(cmd)==>   / q  \tq");
		prl("\t***it ends itself***");
		prl("\t***nvm next***");
		prl("\t(cmd)==>   / s 	T a\t\t Rt");
		prl("\t(calc)==>");
		prl("\t\t\t***after some 10 erros (idk i never counted meh)***");
		prl("\t\t\t***it dies cuz it hates me(as if anything likes me).***");
		prl("");
		break;
	case 2:					// calc
		prl("\t(calc)==>   +++5+++4----1");
		prl("\tResult: 10");
		prl("\t(calc)==>   --5--4--1");
		prl("\tResult: 10");
		prl("\t(calc>==>   5  0       +		3  0  -               8             0");
		prl("\tResult: 0");
		prl("\t\t\t***after 10 errors***");
		prl("\t\t\t***it dies, cuz it hates me(creator)");
		prl("");
		break;
	default:
		break;
	}
}


void help()
{
	if (h < 2)
	{
		prl("   Type \'/h\'   (without the quotes) and press enter for help,");
		prl("   Type \'/qq\'  (without the quotes) and press enter to quit this crap,");
		prl("   Type \'/s\'   (without the quotes) and press enter to start calculating.");
		prl("   Type \'/abt\'   (without the quotes) and press enter to know about me(creator ofc) and this calculator.");
		prl("   Type \'/ust\' (without the quotes) and press enter to show how it works(why?).");
		prl("   Alternates for /s -> /str, /start;");
		prl("   ALternates for /h -> /help.");
	}
	else if (h < 3)
	{
		prl("   WUt!?");
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/s\'   to start calculating.");
		prl("   \'/abt\' to know about me(creator ofc) and this calculator.");
		prl("   \'/ust\' to show how it works(why?).");
		prl("   Alternates for /s -> /str, /start;");
		prl("   ALternates for /h -> /help.");
	}
	else if (h < 5)
	{
		prl("   You have already asked help many times");
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/s\'   to start calculating.");
		prl("   \'/abt\' to know about me and this calculator.");
		prl("   \'/ust\' to show how it works(why?).");
	}
	else if (h < 7)
	{
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/s\'   to start calculating.");
		prl("   \'/abt\' to know about me and this calculator.");
		prl("   \'/ust\' to show how it works(why?).");
	}
	else
	{
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/s\'   to start calculating.");
		prl("   \'/abt\' to know about me and this calculator.");
		prl("   \'/ust\' to show how it works(why?).");
		if (h == 7)
		{
			prl("   Its always good to help so I won\'t quit :|");
			h++;
		}
		return;
	}
	h++;
}

void helpc()
{
	if (hc < 1)
	{
		prl("   Type \'/h\'   (without the quotes) and press enter for help,");
		prl("   Type \'/qq\'  (without the quotes) and press enter to quit this crap,");
		prl("   Type \'/q\'   (without the quotes) and press enter to go back to cmd mode(why?).");
		prl("   Type \'/abt\'   (without the quotes) and press enter to know about me(creator ofc) and this calculator.");
		prl("   Type \'/ust\' (without the quotes) and press enter to show how it works(why?).");
		prl("   ALternates for /h -> /help.");
	}
	else if (hc < 2)
	{
		prl("   WUt!?");
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/abt\' to know about me(creator ofc) and this calculator.");
		prl("   \'/q\'   to go back to cmd mode(why?).");
		prl("   \'/ust\' to show how it works(why?).");
		prl("   ALternates for /h -> /help.");
	}
	else if (hc < 3)
	{
		prl("   You have already asked help many times");
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/abt\' to know about me(creator ofc) and this calculator.");
		prl("   \'/q\'   to go back to cmd mode(why?).");
		prl("   \'/ust\' to show how it works(why?).");
	}
	else if (hc < 5)
	{
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/abt\' to know about me and this calculator.");
		prl("   \'/q\'   to go back to cmd mode(why?).");
		prl("   \'/ust\' to show how it works(why?).");
	}
	else
	{
		prl("   \'/h\'   for help,");
		prl("   \'/qq\'  to quit this crap,");
		prl("   \'/q\'   to go back to cmd mode.");
		prl("   \'/ust\' to show how it works(why?).");
		if (hc == 5)
		{
			prl("   Its always good to help so I won\'t quit :)");
			hc++;
		}
		return;
	}
	hc++;
}




double long pow(int8_t num, int8_t count)
{
	double long res = 1;
	for (int i = 0; i < count; i++)
		res *= num;
	return res;
}


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
