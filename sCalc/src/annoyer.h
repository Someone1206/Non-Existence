#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#define pr(wtf) std::cout << wtf
#define prl(wtf) std::cout << wtf << std::endl



#if _WIN32
#include <Windows.h>
#define WAIT(t) Sleep(t)
#else
#include <unistd.h>
#define WAIT(t) usleep(t * 1000)  // deprecated but okay
#endif // _WIN32


static int index = 0, len = 0;


double pow(int8_t num, int8_t count);

bool ckd(char& c, bool ck = false, bool r = false, bool is_p = false, bool is_ve = false);

bool validex(std::string& exp);

void expForm(std::string& exp);



// couldn't do without functions...

char now(std::string& exp);

char nxt(std::string& exp);

double long toNum(std::string& exp);

double long term(std::string& exp);

double long mulDiv(std::string& exp);

double long expr(std::string& exp);




static const char* help[5] = {
	"   Type \'/h\'   (without the quotes) and press enter for help,\n"
	"   Type \'/qq\'  (without the quotes) and press enter to quit this crap,\n"
	"   Type \'/s\'   (without the quotes) and press enter to start calculating.\n"
	"   Type \'/abt\'   (without the quotes) and press enter to know about me(creator ofc) and this calculator.\n"
	"   Type \'/ust\' (without the quotes) and press enter to show how it works(why?).\n"
	"   Alternates for /s -> /str, /start;\n"
	"   ALternates for /h -> /help.",

	"   WUt!?\n"
	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/s\'   to start calculating.\n"
	"   \'/abt\' to know about me(creator ofc) and this calculator.\n"
	"   \'/ust\' to show how it works(why?).\n"
	"   Alternates for /s -> /str, /start;\n"
	"   ALternates for /h -> /help.\n",

	"   You have already asked help many times\n"
	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/s\'   to start calculating.\n"
	"   \'/abt\' to know about me and this calculator.\n"
	"   \'/ust\' to show how it works(why?).\n",

	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/s\'   to start calculating.\n"
	"   \'/abt\' to know about me and this calculator.\n"
	"   \'/ust\' to show how it works(why?).\n",

	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/s\'   to start calculating.\n"
	"   \'/abt\' to know about me and this calculator.\n"
	"   \'/ust\' to show how it works(why?).\n"
};

static const char* helpc[5] = {
	"   Type \'/h\'   (without the quotes) and press enter for help,\n"
	"   Type \'/qq\'  (without the quotes) and press enter to quit this crap,\n"
	"   Type \'/q\'   (without the quotes) and press enter to go back to cmd mode(why?).\n"
	"   Type \'/abt\'   (without the quotes) and press enter to know about me(creator ofc) and this calculator.\n"
	"   Type \'/ust\' (without the quotes) and press enter to show how it works(why?).\n"
	"   ALternates for /h -> /help.\n",

	"   WUt!?\n"
	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/abt\' to know about me(creator ofc) and this calculator.\n"
	"   \'/q\'   to go back to cmd mode(why?).\n"
	"   \'/ust\' to show how it works(why?).\n"
	"   ALternates for /h -> /help.\n",

	"   You have already asked help many times\n"
	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/abt\' to know about me(creator ofc) and this calculator.\n"
	"   \'/q\'   to go back to cmd mode(why?).\n"
	"   \'/ust\' to show how it works(why?).\n",

	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/abt\' to know about me and this calculator.\n"
	"   \'/q\'   to go back to cmd mode(why?).\n"
	"   \'/ust\' to show how it works(why?).\n",

	"   \'/h\'   for help,\n"
	"   \'/qq\'  to quit this crap,\n"
	"   \'/q\'   to go back to cmd mode.\n"
	"   \'/ust\' to show how it works(why?).\n"
};

static const char* selft[2] = {
	"\t(cmd)==>   /      s\n"
	"\t(calc)==>\n"
	"\t**next**\n"
	"\t(cmd)==>   / q  \tq\n"
	"\t***it ends itself***\n"
	"\t***nvm next***\n"
	"\t(cmd)==>   / s 	T a\t\t Rt\n"
	"\t(calc)==>\n"
	"\t\t\t***after some 10 errors (idk i never counted meh)***\n"
	"\t\t\t***it dies cuz it hates me(as if anything likes me).***\n"
	"\n",

	"\t(calc)==>   +++5+++4----1\n"
	"\tResult: 10\n"
	"\t(calc)==>   --5--4--1\n"
	"\tResult: 10\n"
	"\t(calc>==>   5  0       +		3  0  -               8             0\n"
	"\tResult: 0\n"
	"\t\t\t***after 10 errors***\n"
	"\t\t\t***it dies, cuz it hates me(creator)\n"
	"\n"
};