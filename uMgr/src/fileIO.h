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

enum ReadOptions {
    Anime, Manga, Movies,

    Others
};

enum TrackerFileOptions
{
     LastLogs, G_IndexerAndData, E_IndexerAndData
    // ..., Genre Indexer and data, entry indexer and data
};

bool isspace(str& string1);



// read from files
//
void readFile(ifstream& file, ReadOptions options, int history = 0, bool isLLog = 0);

void readTrackerFile(ifstream& file, TrackerFileOptions tfo, int history = 0);
// history shows no. of history for LastLogs.baka, if > 10 then it shutsdown silently

void readTrackerFile(ifstream& file, bool& choice); // only for settings.baka



// write to files

void splitFile(str& paf, str& nameR, str& leftOver, str& name); // split the name and log

void writeFile(str paf, str& details, str& date, str& time, str name = "");
// write file for others

void writeFile(str paf, str& season, str& episode, str& details, str& date, str& time, str name = "");
// write file for Anime!!!

void writeFile(str paf, str& chapter, str& page, str& details, str& date, str& time, bool shit /* useless param for distinguishing */, str name = "");
// write file for Manga!!!

void writeFile(str paf, str& part, str& details, str& date, str& time, str name = "");
// write file for movies

void writeFile(str paf, bool choice);
