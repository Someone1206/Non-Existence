#include "fileIO.h"

int main() {
    fs::create_directory(folderN);
    {
        str paf = folderN + fsep + "Settings.baka";
        if (!fs::exists((paf))) {
            ofstream f;
            f.open(paf);
            f << 0;
            f.close();
        }
        // idk if this works but does it improve the memory management (by destroying[or whatever it's called] the string var)
        {
            str pa = folderN + fsep + "LastLogs.baka";
            if (!fs::exists(pa)) {
                ofstream file;
                file.open(pa);
                file << (char)1 << endl;
                file.close();
            }
        }
        {
            bool createPredefinedGenre = 1;
            str pa = folderN + fsep;
            ifstream file;
            file.open(paf);

            readTrackerFile(file, createPredefinedGenre);

            if (createPredefinedGenre) {
                fs::create_directory((pa + "Anime"));
                fs::create_directory((pa + "Manga"));
                fs::create_directory((pa + "Movies"));
            }
        }
    }
    ifstream file;
    file.open((folderN + fsep + "LastLogs.baka"));
    readTrackerFile(file, LastLogs, 2);
    return 0;
}
