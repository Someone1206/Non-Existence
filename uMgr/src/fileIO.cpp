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
 * <entry>
 * (char)1
 * (char)1
 * ...
 * ...
 * ...
 * ... shows last 10 logs
 *
 * <!-- AllLogs.hentai -->
 * <-- may be really memory intensive -->
 * (char)1
 * <genre>
 * <entry>
 * (char)1
 * (char)1
 * ...
 * ...
 * ...
 * ... stores and may show all logs
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


void writeToal(str& data, str& genre) {
    str paf = folderN + fsep + "AllLogs.hentai";
    ifstream fileR(paf);
    if (!fileR.is_open()) {
        prl(fileR.is_open());
        prl("くそが! Can't open AllLogs.hentai ditch me");
        return;
    }
    str tempFilePaf = paf + ".temp";
    ofstream fileW(tempFilePaf);
    fileW << (char)1 << endl;
    {
        str temp = "";
        while (getline(fileR, temp))
            fileW << temp << endl;
    }

    fileR.close();
    fileW.close();
    {
        ofstream fileReW(paf);
        ifstream fileRe(tempFilePaf);
        
        fileReW << (char)1 << endl << genre << endl << data << endl;

        {
            str temp = "";
            while (getline(fileRe, temp))
                fileReW << temp << endl;
        }
    }
    fs::remove(tempFilePaf);
}

void writeToll(str& data, str& genre) {
    str paf = folderN + fsep + "LastLogs.baka";
    ifstream fileR(paf);
    if (!fileR.is_open()) {
        prl(fileR.is_open());
        prl("くそが! Can't open LastLogs.baka ditch me");
        return;
    }
    str tempFilePaf = paf + ".temp";
    
    ofstream fileW(tempFilePaf);
    
    fileW << (char)1 << endl;
    // write to temp file
    {
        str temp = "";
        while (getline(fileR, temp))
            fileW << temp << endl;
    }

    fileR.close();
    fileW.close();
    {
        ofstream fileReW(paf);
        ifstream fileRe(tempFilePaf);
        
        fileReW << (char)1 << endl << genre << endl << data << endl;

        int count = 0;
        str temp = "";
        char c = (char)1;

        while (getline(fileRe, temp) && count < 20) {
            if (temp.find(c) == str::npos)
                count++;
            fileReW << temp << endl;
        }
        
    }
    fs::remove(tempFilePaf);
}

// a really inefficient way of writing to the starting of file
void writeFile(str paf, str& data, str genre, int option, str name) {

    if ((option & Create) == Create)
    {
        if (!fs::exists(paf))
        {
            ofstream file(paf);
            if (isspace(name))
            {
                prl("No name provided");
                return;
            }
            file << name << endl << (char)1 << endl;
        }
    }
    if ((option & NQuit) == NQuit)
        return;
    if ((option & Add) == Add) {
        std::thread wAllLog(writeToal, ref(data), ref(genre));
        std::thread wll(writeToll, ref(data), ref(genre));
        
        ifstream fileR(paf);
        if (!fileR.is_open()) {
            prl(fileR.is_open());
            prl("Damn! Can't open a file, I am useless ditch me.");
            return;
        }

        str tempFilePaf = paf + ".temp", name = "";

        ofstream fileW(tempFilePaf);
        getline(fileR, name);
        // write to temp file
        {
            str temp = "";
            while (getline(fileR, temp))
                fileW << temp << endl;
        }
        fileR.close();
        fileW.close();

        // rewriting to the file again
        {
            ofstream fileReW(paf);
            ifstream fileR(tempFilePaf);
            fileReW << name << endl << (char)1 << endl;
            fileReW << data << endl;

            str temp = "";
            while (getline(fileR, temp))
                fileReW << temp << endl;
        }
        fs::remove(tempFilePaf);

        wll.join();
        wAllLog.join();
    }
}


// only for settings file
void writeFile(bool choice, str paf) {
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