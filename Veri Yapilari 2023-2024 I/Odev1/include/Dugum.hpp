#ifndef Dugum_HPP
#define Dugum_HPP

#include <iostream>
#include "Sayi.hpp"
using namespace std;

class Dugum{
	public:
	    Sayi* item;
		Dugum* next;
		
		Dugum(Sayi* item,Dugum* next);
		Dugum(Sayi* item);
};

#endif