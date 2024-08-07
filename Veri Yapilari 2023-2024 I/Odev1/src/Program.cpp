#include <iostream>
#include "FileManager.hpp"
#include "StringManager.hpp"
#include "Sayi.hpp"
#include "NumberManager.hpp"
#include "SayilarListesi.hpp"

using namespace std;


int main() {
    system("CLS");
    FileManager* fm = new FileManager("Sayilar.txt");
    StringManager* sm = new StringManager();
    string line  = fm->get_line();
    SayilarListesi* sayilarListesi = new SayilarListesi();

    string* numbers = StringManager::split(line, " ");
    int slicesCount = StringManager::get_slices_count(line, " ");
    for (int j = 0; j < slicesCount; j++)
    {
        sayilarListesi->add(new Sayi(numbers[j]));
    }
        
    cout << *sayilarListesi;
    int sayac = 0;

    int secim = 0;
    bool devam = true;
    while(devam && sayilarListesi->size() > 0){
        cout << "1_Reverse"<<endl;
        cout << "2_Move Odd Numbers" << endl;
        cout << "3_Remove Biggest" << endl;
        cout << "4_Cikis" << endl;

        cin >> secim;
        switch(secim){
            case 1:
                sayilarListesi->reverse_all();
                break;
            case 2:
                sayilarListesi->take_odd_to_first_all();
                break;
            case 3:
                sayilarListesi->remove_biggest();
                break;
            default:
                devam = false;
                break;
        }
        system("CLS");
        cout << *sayilarListesi;
    }
    cout << "Program bitti ! Gule gule";
    return 0;
}