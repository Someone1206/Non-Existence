#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <thread>

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

enum ReadOptions {
    Anime, Manga, Movies,

    Others
};

enum WriteOption
{
    Create, Add, NQuit, LogIt, NLogIt
};

enum TrackerFileOptions
{
     LastLogs, G_IndexerAndData, E_IndexerAndData
    // ..., Genre Indexer and data, entry indexer and data
};

bool isspace(str& string1);


// read from files
void readFile(ifstream& file, ReadOptions options, int history = 0, bool isLLog = 0);

// history shows no. of history for LastLogs.baka, if > 10 then it shutsdown silently
void readTrackerFile(ifstream& file, TrackerFileOptions tfo, int history = 0);

void readTrackerFile(ifstream& file, bool& choice); // only for settings.baka



// write to files
void writeFile(str paf, str& data, str genre = "Anime", int option = Create, str name = "");
// write to setting file
void writeFile(bool choice, str paf = (folderN + fsep + "Settings.baka"));
