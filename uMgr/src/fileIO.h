#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

#define pr(wtf) cout << wtf
#define prl(wtf) cout << wtf << endl

#if _WIN32
#define fsep '\\'
#else
#define fsep '/'
#endif

using str = std::string;
namespace fs = std::filesystem;

static str folderN = "uMgrData";

enum Options {
    Anime, Manga, Movies,

    Others
};

bool isspace(str& string1);

void readFile(ifstream& file, Options options, int history = 0, str paf = "");