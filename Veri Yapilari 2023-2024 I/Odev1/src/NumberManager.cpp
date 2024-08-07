#include "NumberManager.hpp"


NumberManager::NumberManager(int number){
    this->number = number;
    calc_number_length();
}
int NumberManager::get_number(){
    return this->number;
}
void NumberManager::set_number(int number){
    this->number = number;
    calc_number_length();
}
void NumberManager::calc_number_length(){
    number_length = 0;
    int tempNumber = number;
    while(tempNumber != 0){
        tempNumber /= 10;
        number_length++;
    }
}
int NumberManager::get_number_length(){
    return number_length;
}
int* NumberManager::get_number_digits(){
    int* digits = new int[number_length];
    int index = 0;

    // splitting the digits;
    int tempNumber = number;
    while(tempNumber != 0){
        int digit = tempNumber % 10;
        tempNumber /= 10;
        digits[index] = digit;
        
        index++;
    }

    int* temp = new int[number_length];
    // reverse the digits
    for(int i = 0; i < number_length ; i++){
        temp[i] = digits[number_length - i - 1];
    }
    return temp;
}