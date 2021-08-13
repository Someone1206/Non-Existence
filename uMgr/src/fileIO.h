#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

#define pr(wtf) cout << wtf;
#define prl(wtf) cout << wtf << endl;

#if _WIN32
#define fsep '\\'
#else
#define fsep '/'
#endif // _WIN32


using str = string;
namespace fs = filesystem;

static str folderN = "uMgrData";

bool isspace(str& s);