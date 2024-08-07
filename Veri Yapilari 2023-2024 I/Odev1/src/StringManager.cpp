#include "StringManager.hpp"

string* StringManager::split(string str,string delimiter){
    size_t pos = 0;
    string token;
    int slices_count = get_slices_count(str,delimiter);
    string* splitted_array = new string[slices_count];
    int i = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        splitted_array[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
    splitted_array[i] = str;

    return splitted_array;
}
int StringManager::get_slices_count(string str, string delimiter){
    int count = 0;
    for (char ch : str) {
        if (ch == ' ') {
            count++;
        }
    }
    count++;
    return count;
}
string StringManager::get_last_of_address(string& address){
    string adrs = "";
    for(int i = 5 ; i < 8 ; i++){
        adrs += address[i];
    }
    //adrs = address.substr(5,3); substring didn't work for some reason
    
    return adrs;
}