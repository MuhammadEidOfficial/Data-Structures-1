#ifndef Basamak_HPP
#define Basamak_HPP
///======///
#include <iostream>
using namespace std;

class Basamak{
	public:
	    int item;
		Basamak* next;
		
		Basamak(const int& item,Basamak* next);
		Basamak(const int& item);
};

#endif