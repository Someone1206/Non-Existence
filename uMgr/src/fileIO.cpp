#include "fileIO.h"

bool isspace(str& string1) {
    const char* c = string1.c_str();

    for (int i = 0; i < string1.length(); ++i)
        if (isspace(*c++))
            return false;
    return true;
}

/* ******************************************************************************
 *
 * How the file will be read (this is bound to change):
 * <!-- Others:  distinguished by file names-->
 * <name>
 * (char)1
 * <date>
 * <time>
 * <details> ...optional
 * (char)1
 * <date>
 * <time>
 * <details> ...optional
 *
 * <!-- Anime:  distinguished by file names-->
 * <name>
 * (char)1
 * <date>
 * <time>
 * <season>  ...optional
 * <episode> ...optional
 * <details> ...optional
 * (char)1
 *
 * <!-- Manga:  distinguished by file names-->
 * <name>
 * (char)1
 * <date>
 * <time>
 * <chapter> ...optional
 * <page>    ...optional
 * <details> ...optional
 * (char)1
 *
 * <!-- Movies:  distinguished by file names-->
 * <name>
 * (char)1
 * <date>
 * <time>
 * <part>    ...optional
 * <details> ...optional
 * (char)1
 *
 *
 * <!-- Tracker File Formats -->
 *
 *
 * <!-- Settings.baka (G_Set)-->
 * <choice>
 *
 *
 * <!-- LastLogs.baka (LastLogs)-->
 * (char)1
 * <genre>
 * <name>
 * <details>
 * (char)1
 * (char)1
 * ...
 * ...
 * ...
 * ...shows last 10 logs
 *
 *
 * <!-- GenIndexer.baka (G_IndexerAndData)-->
 *
 * <!!-- Names to display for the Genre --!>
 * <-- some OS may not support Unicode in its filesystem (which OS is so damn outdated?)
 * or may show errors or stupid behaviours for some characters (I'm not trying to say that
 * English is great but I've seen some linux distros do that, Windows doesn't show any problems
 * its good -->
 *
 * <!-- EntryIndexerEng.baka -->
 *
 * <!!-- Names to display for the Entry --!>
 *
 * ******************************************************************************
 */

void readFile(ifstream& file, ReadOptions options, int history, bool isLLog) {

    if (!file.is_open())
        prl("Fak can't open file... I suck! Trash me!");

    str line = "";
    int counter = 0;

    history = (bool)history * history + ((!(bool)history) * -1) + (((bool)history) * 1); 
    /*
     * ☝☝this takes avg. of 1000 μs when numbers are between 0 and 50
     *
     *
     * if (history > 0)
     *     history++;
     * else
     *     history = -1;
     * ☝☝ this takes avg of 1000 μs when numbers are large (>500 idk y?)
     * when 0, avg of 2100 μs is needed, therefore, its inefficient.
     * 
     * here μ = https://seeklogo.com/images/M/mew-logo-8F891D0488-seeklogo.com.png
    */
    // if history is 0, print all -> -1, else print the number of logs from first and add 1 to it
    getline(file, line);
    prl("Name:");
    prl(line << "\n\n\n");


    while (getline(file, line) && ((bool)history)) {
        if (line.find((char)1) != std::string::npos)
        {
            if (isLLog)
                return;
            counter = 0;
            history--;
            continue;
        }
        switch (counter) {
        case 0:
            prl("Date:" << "\t\t" << line << '\n');
            break;
        case 1:
            prl("Time:" << "\t\t" << line);
            break;
        default:
            switch (options) {
            case Others:
                if (counter == 2)
                    prl("Details and Remarks:");
                prl(line);
                break;
            case Anime:
                if (counter == 2)
                    prl("Season:\t\t" << line);
                else if (counter == 3)
                    prl("Episode:\t" << line);
                else {
                    if (counter == 4)
                        prl("Details and Remarks:");
                    prl(line);
                }
                break;

            case Manga:
                if (counter == 2)
                    prl("Last Chapter read:\t\t" << line);
                else if (counter == 3)
                    prl("Page read last:\t\t" << line);
                else {
                    if (counter == 4)
                        prl("Details and Remarks:");
                    prl(line);
                }
                break;

            case Movies:
                if (counter == 2)
                    prl("Part last seen:\t" << line);
                else {
                    if (counter == 3)
                        prl("Details and Remarks:");
                    prl(line);
                }
            }
        }
        counter++;
    }
}

void readTrackerFile(ifstream& file, TrackerFileOptions tfo, int history) {
    if (!file.is_open()) {
        prl("Can't open file");
        return;
    }

    str line = "";
    int i = 0;
    bool isGenN = 0;


    switch (tfo) {
    case G_IndexerAndData:
    case E_IndexerAndData:

        while (getline(file, line) || ((bool)++i))
            prl(i << '\t' << line);
        break;
    case LastLogs:

        while (getline(file, line)) {
            if (line.find((char)1) != str::npos) {
                isGenN = 1;
                continue;
            }
            if (isGenN) {
                if (line.find("Anime") == 0)
                    readFile(file, Anime, 1, 1);
                else if (line.find("Manga") == 0)
                    readFile(file, Manga, 1, 1);
                else if (line.find("Movies") == 0)
                    readFile(file, Movies, 1, 1);
                else
                    readFile(file, Others, 1, 1);
            }
            isGenN *= 0;
        }
        break;
    default:
        prl("\nWrong Choice! Damn, cmon edit the source code");
    }
}


void readTrackerFile(ifstream& file, bool& choice) {
    str validation;
    char c;

    while (getline(file, validation)) {
        c = validation.at(0);
        if (validation == "")
            choice = 1;
        else if ((c >= '0' || c <= '9') && validation.length() == 1) {
            choice = (c - '0');
            return;
        }
        else {
            prl("Error reading settings file");
            break;
        }
    }
}





// !!!!!! for Anime ofc !!!!!!
void writeFile(str paf, str& season, str& episode, str& details, str& date, str& time, str name) {
    str line = "", nameR = "";

    splitFile(paf, nameR, line, name);

    ofstream fileOUT(paf);

    fileOUT << nameR << endl;
    fileOUT << (char)1 << endl;
    fileOUT << date << endl << time << endl << season << endl << episode << endl;
    fileOUT << details << endl;
    fileOUT << line;
}

// for Manga ofc!!!
void writeFile(str paf, str& chapter, str& page, str& details, str& date, str& time, bool shit, str name) {
    str line = "", nameR = "";

    splitFile(paf, nameR, line, name);

    ofstream fileOUT(paf);

    fileOUT << nameR << endl;
    fileOUT << (char)1 << endl;
    fileOUT << date << endl << time << endl << chapter << endl << page << endl;
    fileOUT << details << endl;
    fileOUT << line;
}

// write file for Movies!
void writeFile(str paf, str& part, str& details, str& date, str& time, str name) {
    str line = "", nameR = "";

    splitFile(paf, nameR, line, name);

    ofstream fileOUT(paf);

    fileOUT << nameR << endl;
    fileOUT << (char)1 << endl;
    fileOUT << date << endl << time << endl << part << endl;
    fileOUT << details << endl;
    fileOUT << line;
}

// for others
void writeFile(str paf, str& details, str& date, str& time, str name) {
    str line = "", nameR = "";

    splitFile(paf, nameR, line, name);

    ofstream fileOUT(paf);

    fileOUT << nameR << endl;
    fileOUT << (char)1 << endl;
    fileOUT << date << endl << time << endl << details << endl;
    fileOUT << line;
}

// only for settings file
void writeFile(str paf, bool choice) {
    ofstream file;
    
    if (!fs::exists(paf)) {
        ofstream f;
        f.open(paf);
        f << 1;
        f.close();
    }
    file.open(paf);
    file << choice;
    file.close();
}

void splitFile(str& paf, str& nameR, str& leftOver, str& name) {
    if (!fs::exists(paf)) {
        ofstream file;
        file.open(paf);
        file << name << endl;
        file << (char)1;
        file.close();
    }

    ifstream fileIN;
    fileIN.open(paf);

    getline(fileIN, nameR);

    str temp = "";
    while (getline(fileIN, temp))
        leftOver = leftOver + temp + '\n';
}