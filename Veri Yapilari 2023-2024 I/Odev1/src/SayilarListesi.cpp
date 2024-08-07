#include "SayilarListesi.hpp"

Dugum* SayilarListesi::FindPrevByPosition(int position){
    if(position < 0 || position > size()) throw "Index out of range";
    int index=0;
    Dugum *itr=head;
    for(;itr!=NULL;itr=itr->next,index++){
        if(position == index) return itr;
    }
    return NULL;
}	
int SayilarListesi::address_length(Sayi* itr){
    const void * address = static_cast<const void*>(itr);
    std::stringstream ss;
    ss << address;  
    std::string str = ss.str(); 
    return str.length();
}
SayilarListesi::SayilarListesi(){
    head = new Dugum(new Sayi());
}
bool SayilarListesi::isEmpty() const{
    return head->next == NULL;
}
int SayilarListesi::size() const{
    int length=0;
    for(Dugum *itr=head->next;itr!=NULL;itr=itr->next){
        length++;
    }
    return length;
}
void SayilarListesi::add(Sayi* item){
    insert(size(),item);
}
void SayilarListesi::insert(int index,Sayi* item){
    Dugum *prev = FindPrevByPosition(index);
    prev->next = new Dugum(item,prev->next);
}
void SayilarListesi::removeAt(int index){
    if(isEmpty()) throw "Empty list";
    Dugum *del;
    Dugum *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;
    
    delete del;
}
void SayilarListesi::reverse_all() {
    if(isEmpty())
        return;
    for(Dugum* itr = head->next; itr != NULL; itr = itr->next){
        itr->item->reverse();
    }
}
void SayilarListesi::take_odd_to_first_all(){
    if(isEmpty())
        return;
    for(Dugum* itr = head->next; itr != NULL; itr = itr->next){
        itr->item->take_odd_to_first();
    }
}
void SayilarListesi::remove_biggest(){
    int index = find_index_of_biggest();    
    removeAt(index);
}
int SayilarListesi::find_index_of_biggest(){
    if(isEmpty())
        throw "Empty List";
    int maxItem = INT_MIN;
    int result = -1;
    int i =0;
    for(Dugum* itr = head->next; itr != NULL; itr = itr->next,i++){
        if(itr->item->get_sayi() > maxItem){
            result = i;
            maxItem = itr->item->get_sayi();
        }
    }
    return result;
}
void SayilarListesi::clear(){
    while(!isEmpty())
        removeAt(0);
}
ostream& operator<<(ostream& screen, SayilarListesi& right) {

    int index = 0;
    for (Dugum* itr = right.head->next; itr != NULL; itr = itr->next,index++) {
        int address_length = right.address_length(itr->item);
        int padding = 9 - address_length;
        right.gotoxy(0,index*6);
        screen <<"##############" << std::endl;
        // right.gotoxy(0,index*6 + 1);
        screen <<"#" << std::right << std::setw(2) << " ";
        screen << itr->item;
        screen <<std::right << std::setw(2 + padding)<<"#"<< std::endl;
        // right.gotoxy(0,index*6 + 2);
        screen << "#";
        screen << "------------";
        screen << "#"<< std::endl;
        // right.gotoxy(0,index*6 + 3);
        screen << "#";
        screen << std::right <<  std::setw(12) << itr->item->get_sayi();
        screen << "#"<< std::endl;
        // right.gotoxy(0,index*6 + 4);
        screen <<"##############";
        itr->item->print(20,index*6);
        screen << std::endl;
    }
    return screen;
}
void SayilarListesi::print(){
    int index = 0;
    for (Dugum* itr = head->next; itr != NULL; itr = itr->next) {
        itr->item->print(20,index*6);
        index++;
    }
}
void SayilarListesi::gotoxy(int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
SayilarListesi::~SayilarListesi(){
    clear();	
    delete head;
}   