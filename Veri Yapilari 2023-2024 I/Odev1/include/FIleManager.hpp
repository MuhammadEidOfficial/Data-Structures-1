#ifndef FileManager_Hpp
#define FileManager_Hpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileManager{
    private:
    int linesCount;
    string path;
    bool is_end_of_file(ifstream& file);
    public:
    FileManager(string path);
    string* get_all_lines();
    int get_line_count();
    string get_line();
    // path, string[] lines, int linesCount

};

#endif