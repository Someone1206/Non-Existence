#include "fileIO.h"

int main() {
    fs::create_directory(folderN);
    {
        str paf = folderN + fsep + "Settings.baka";
        if (!fs::exists((paf))) {
            ofstream f;
            f.open(paf);
            f.close();
        }
        // idk if this works but does it improve the memory management (by destroying[or whatever it's called] the string var)
        {
            str pa = folderN + fsep + "LastLog.baka";
            if (!fs::exists(pa)) {
                ofstream file;
                file.open(pa);
                file << (char)1 << endl;
                file.close();
            }
        }
        {
            bool createPredefinedGenre = 1;
            str validation, pa = folderN + fsep;
            char c;
            ifstream file;
            file.open(paf);
            while (getline(file, validation)) {
                c = validation.at(0);
                if (validation == "")
                    createPredefinedGenre = 1;
                else if ((c >= '0' || c <= '9') && validation.length() == 1)
                    createPredefinedGenre = (c - '0');
                else {
                    prl("Error reading settings file");
                    break;
                }
            }
            if (createPredefinedGenre) {
                fs::create_directory((pa + "Anime"));
                fs::create_directory((pa + "Manga"));
                fs::create_directory((pa + "Movies"));
            }
        }
    }
    ifstream file;
    file.open((folderN + fsep + "Anime" + fsep + "Date A Live.log"));
    readFile(file, Anime, 2); // Anime, Manga, Movies and Others work fabulously! Okay, I didn't take any errors into account while reading the file
    // looking at the formatting of the file, it seems if you play with the files nad mess up, you screwed yourself. 
    // cuz there's no way to detect errors according to the syntax but will probably come soon, I guess (that's a big guess).
    return 0;
}
