#ifndef StringManager_HPP
#define StringManager_HPP

#include <iostream>
#include <string>
using namespace std;
class StringManager{

    private:

    public:
    static string* split(string str,string delimiter);
    static int get_slices_count(string str, string delimiter);
    static string get_last_of_address(string& adress);
};

#endif