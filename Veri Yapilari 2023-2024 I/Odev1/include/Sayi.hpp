#ifndef Sayi_HPP
#define Sayi_HPP

#include "Basamak.hpp"
#include "StringManager.hpp"
#include "NumberManager.hpp"
#include <string>
#include <iomanip>
#include <windows.h>
#include <sstream> 
class Sayi{
	private:
		Basamak* head;
        Basamak* FindPrevByPosition(int position);
		string address_to_string(Basamak*);
		NumberManager* numberManager;
		void gotoxy(int,int);
		int cor_y;
		void swap_nodes(Basamak*,Basamak*,Basamak*);
		int sayi;
		int GetConsoleCursorPosition(HANDLE hConsoleOutput);

	public:
		Sayi();
		Sayi(int number);
		Sayi(string numberStr);
		int get_sayi();
		void set_cor_y(int);
		bool isEmpty() const;
		int size() const;
		void add(const int& item);
		void insert(int index,const int& item);
		void removeAt(int index);
		void reverse();
		void take_odd_to_first();
		void print(int,int);
		friend ostream& operator<<(ostream& screen, Sayi &right);
		void clear();
		~Sayi();
};
#endif