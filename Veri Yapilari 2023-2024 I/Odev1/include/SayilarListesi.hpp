#ifndef SayilarListesi_HPP
#define SayilarListesi_HPP

#include "Sayi.hpp"
#include "Dugum.hpp"
#include <limits.h>
#include <iomanip>
#include <sstream> 
class SayilarListesi{
	private:
		Dugum* head;
        Dugum* FindPrevByPosition(int position);
		string address_to_string(Dugum*);
		void gotoxy(int,int);
		int find_index_of_biggest();
		int address_length(Sayi*);

	public:
		SayilarListesi();
		bool isEmpty() const;
		int size() const;
		void add(Sayi* item);
        void insert(int index,Sayi* item);
		void removeAt(int index);
		void reverse_all();
		void take_odd_to_first_all();
		void remove_biggest();
		void print();
		friend ostream& operator<<(ostream& screen, SayilarListesi
     &right);
		void clear();
		~SayilarListesi();
};
#endif