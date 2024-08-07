#ifndef NumberManager_hpp
#define NumberManager_hpp
#include <string> 
#include <iostream> 
class NumberManager{

    private:
    int number;
    int number_length;
    void calc_number_length();
    public:
    NumberManager(int);
    int get_number();
    void set_number(int);
    int get_number_length();
    int* get_number_digits();
};

#endif