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

// why 2 different enums? ytf not?

enum TrackerFileOptions
{
     LastLogs, G_IndexerAndData, E_IndexerAndData
    // ..., Genre Indexer and data, entry indexer and data
};

bool isspace(str& string1);

void readFile(ifstream& file, Options options, int history = 0, str paf = "");

void readTrackerFile(ifstream& file, TrackerFileOptions tfo, int history = 0);
// history shows no. of history for LastLogs.baka, if > 10 then it shutsdown silently

void readTrackerFile(ifstream& file, bool& choice); // only for settings.baka
