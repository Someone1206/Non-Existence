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
 * (char)0
 * <date>
 * <time>
 * <details> ...optional
 * (char)0
 * <date>
 * <time>
 * <details> ...optional
 *
 * <!-- Anime:  distinguished by file names-->
 * <name>
 * (char)0
 * <date>
 * <time>
 * <season>  ...optional
 * <episode> ...optional
 * <details> ...optional
 * (char)0
 *
 * <!-- Manga:  distinguished by file names-->
 * <name>
 * (char)0
 * <date>
 * <time>
 * <chapter> ...optional
 * <page>    ...optional
 * <details> ...optional
 * (char)0
 *
 * <!-- Movies:  distinguished by file names-->
 * <name>
 * (char)0
 * <date>
 * <time>
 * <part>    ...optional
 * <details> ...optional
 * (char)0
 *
 * <!-- Settings.baka -->
 * <choice>
 *
 *
 * <!-- LastLogs.baka -->
 * <genre>
 * <name>
 * <details>
 * (char)0
 * ...
 * ...
 * ...
 * ...shows last 10 logs
 * ******************************************************************************
 */

void readFile(ifstream& file, Options options, int history, str paf) {

    if (!file.is_open()) {
        file.open(paf);
        if (!fs::exists(paf)) {
            prl("Error Opening file");
            return;
        }
    }

    str line = "";
    int counter = 0; 

    history = (bool)history * history + ((!(bool)history) * -1) + (((bool)history) * 1); // problem here
    // if history is 0, print all -> -1, else print the number of logs from first and add 1 to it
    getline(file, line);
    prl("Name:");
    prl(line);

    switch (options) {
    case Others:
        
        while (getline(file, line) && ((bool)history)) {
            
            if (line.find((char)1) != std::string::npos) {
                counter = 0;
                history--;
                continue;
            }
            
            switch (counter)
            {
            case 0:
                prl("Date:" << '\n' << line << '\n');
                break;
            case 1:
                prl("Time:" << '\n' << line);
                break;
            case 2:
                prl("Details:");
            default:
                prl(line);
            }
            counter++;
        }
        break;

    }

    while (getline(file, line) && ((bool)history)) {
        if (line.find((char)1) != std::string::npos)
        {
            counter = 0;
            history--;
            continue;
        }
        switch (counter) {
        case 0:
            prl("Date:" << '\n' << line << '\n');
            break;
        case 1:
            prl("Time:" << '\n' << line);
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
                    prl("Season:\t" << line);
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
                    prl("Last Chapter read:\t" << line);
                else if (counter == 3)
                    prl("Page read last:\t" << line);
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
