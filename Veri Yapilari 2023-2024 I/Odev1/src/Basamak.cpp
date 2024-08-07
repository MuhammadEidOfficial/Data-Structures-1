#include "Basamak.hpp"

		
Basamak::Basamak(const int& item,Basamak* next){
    this->item = item;
    this->next = next;
}
Basamak::Basamak(const int& item){
    this->item = item;
    this->next = NULL;
}