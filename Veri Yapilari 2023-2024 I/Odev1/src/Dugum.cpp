#include "Dugum.hpp"
		
Dugum::Dugum(Sayi* item,Dugum* next){
    this->item = item;
    this->next = next;
}
Dugum::Dugum(Sayi* item){
    this->item = item;
    this->next = NULL;
}