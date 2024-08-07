#include "FileManager.hpp"

bool FileManager::is_end_of_file(ifstream& file){
    return file.peek() == EOF;
}
int FileManager::get_line_count(){
    ifstream file(path);
    int count = 0;
    while(!is_end_of_file(file)){
        string line;
        getline(file,line);
        count++;
    }
    return count;
}
FileManager::FileManager(string path){
    this->path = path;
}
string* FileManager::get_all_lines(){
    int lines_count = get_line_count();
    ifstream file(path);
    if(lines_count > 0){
        string* lines = new string[lines_count];
        for(int i = 0 ; i < lines_count ; i++)
        {
            getline(file,lines[i]);
        }
        return lines;
    }
    return NULL;
}
string FileManager::get_line(){
    ifstream file(path);
    string line;
    getline(file,line);
    return line;
}