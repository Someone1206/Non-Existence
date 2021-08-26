#include "fileIO.h"

int main() {
    fs::create_directory(folderN);
    {
        str paf = folderN + fsep + "Settings.baka";
        if (!fs::exists((paf))) {
            ofstream f;
            f.open(paf);
            f << 1;
            f.close();
        }
        // idk if this works but does it improve the memory management (by destroying[or whatever it's called] the string var)
        {
            str pa = folderN + fsep + "LastLogs.baka";
            if (!fs::exists(pa)) {
                ofstream file;
                file.open(pa);
                // file << (char)1;
                file.close();
            }
        }
        {
            str pa = folderN + fsep + "AllLogs.hentai"; // dafuq 😂🤣😅
            if (!fs::exists(pa)) {
                ofstream file;
                file.open(pa);
                // file << (char)1;
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
                fs::create_directory((pa + "BTS"));       // BTS is one of the best... fu if u don't like it, idc
                fs::create_directory((pa + "BLACKPINK")); // hmm... I like BLACKPINK but not as much as BTS. Also fu if u don't like it, I still don't care
            }
        }
    }

    str details = "subarashiiine", date = "58th August, 696969", time = "69:69:69 a.p.m";
    str paf = folderN + fsep + "smth.txt", data = date + '\n' + time + '\n' + "2" + '\n' + "2" + '\n' + details;

    writeFile(paf, data, "Anime", Create | Add, "Date A Live");
    return 0;
}
