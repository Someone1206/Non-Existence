# This crap here is just a framework for writing to and reading from files
---
It reads and writes files according to the syntax given [here](https://github.com/Someone1206/Non-Existence/blob/dad58eea2bfdfdf144dd272e9180f9339f8bce6f/uMgr/uMgrCli/fileIO.cpp#L12).  
It dosen't need any vs proj or sln files, you can get away with mingw or clang in linux with:  
g++:
```
g++ -o shit uMgr.cpp fileIO.cpp -s -O3 -pthread -std=c++17
```
clang++:
```
clang++ -o wtf uMgr.cpp fileIO.cpp -O3 -pthread -std=c++17 -Wall
```
---
I'm not sure about windows because mingw gives stupid, fu*#ed up errors. Clang gives no damn stupid errors ,therefore, you get that:
```
clang++ -O3  uMgr.cpp fileIO.cpp -o uMgr.exe -pthread -std=c++17 -Wall
```
(mind you clang sometimes gives large executable sizes so you may need more optimization flags for both win and linux)
