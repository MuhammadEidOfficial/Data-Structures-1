#include "Sayi.hpp"
Basamak* Sayi::FindPrevByPosition(int position){
    if(position < 0 || position > size()) throw "Index out of range";
    int index=0;
    Basamak *itr=head;
    for(;itr!=NULL;itr=itr->next,index++){
        if(position == index) return itr;
    }
    return NULL;
}	
string Sayi::address_to_string(Basamak* itr){
    const void * address = static_cast<const void*>(itr);
    std::stringstream ss;
    ss << address;  
    std::string str = ss.str(); 
    return str;
}
Sayi::Sayi(){
    head = new Basamak(int());
    cor_y = 0;
    sayi = -1;
}
Sayi::Sayi(int number){
    head = new Basamak(int());
    sayi = number;
    numberManager = new NumberManager(number);
    int* numbers = numberManager->get_number_digits();
    int numberLength = numberManager->get_number_length();
    for(int i = 0 ; i < numberLength; i++){
        add(numbers[i]);
    }
    delete[] numbers;
    cor_y = 0;
}
Sayi::Sayi(string numberStr): Sayi::Sayi(stoi(numberStr)) {}
int Sayi::get_sayi(){
    return sayi;
}
void Sayi::set_cor_y(int y){
    cor_y = y;
}
bool Sayi::isEmpty() const{
    return head->next == NULL;
}
int Sayi::size() const{
    int length=0;
    for(Basamak *itr=head->next;itr!=NULL;itr=itr->next){
        length++;
    }
    return length;
}
void Sayi::add(const int& item){
    insert(size(),item);
}
void Sayi::insert(int index,const int& item){
    Basamak *prev = FindPrevByPosition(index);
    prev->next = new Basamak(item,prev->next);
}
void Sayi::removeAt(int index){
    if(isEmpty()) throw "Empty list";
    Basamak *del;
    Basamak *prev = FindPrevByPosition(index);
    del = prev->next;
    prev->next = prev->next->next;
    
    delete del;
}
void Sayi::reverse() {
    Basamak* cur = head->next;
    Basamak* next = NULL;
    Basamak* prev = NULL;

    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = prev;
}
void Sayi::take_odd_to_first(){
	Basamak* cur = head->next;
	Basamak* next = NULL;
	Basamak* toSwap = NULL;
	Basamak* prev = head;
	while (cur != NULL) {
		next = cur->next;
		if (cur->item % 2 == 1) {
			if (toSwap != NULL) {
                swap_nodes(toSwap,cur,prev);
				toSwap = cur;
			}
			else
			{
				prev = cur;
			}
		}
		else {
			if (toSwap == NULL) {
				toSwap = prev;
			}
			prev = cur;
		}
		cur = next;
	}
}
void Sayi::swap_nodes(Basamak* toSwap,Basamak* cur,Basamak* prev){
    Basamak* tmp = toSwap->next;
    Basamak* tmp2 = cur->next;
    toSwap->next = cur;
    cur->next = tmp;
    prev->next = tmp2;
}
void Sayi::clear(){
    while(!isEmpty())
        removeAt(0);
}
ostream& operator<<(ostream& screen, Sayi& right) {
    //string value = "";
    //if (right.isEmpty()) value = "Empty list";
    //else {
    //    for (Basamak* itr = right.head->next; itr != NULL; itr = itr->next) {
    //        value = value + to_string(itr->item) + "->";
    //    }
    //    value = value.substr(0, value.length() - 2);
    //}
    //value = "";
    //screen << value;
    int x = 20;
    int y = 0;
    for (Basamak* itr = right.head->next; itr != NULL; itr = itr->next) {
        y = right.cor_y;
        right.gotoxy(x, y);
        screen << "*******";
        y++;
        right.gotoxy(x, y);
        screen << "* ";
        string address = right.address_to_string(itr);
        screen << StringManager::get_last_of_address(address);
        screen << " *";
        screen << "\n";
        y++;
        right.gotoxy(x, y);
        screen << "*******";
        screen << "\n";
        y++;
        right.gotoxy(x, y);
        screen << "*";
        int totalWidth = 4;
        int padding = (totalWidth - 1) / 2 + 1;
        screen << std::setw(padding + 1) << itr->item;
        screen << std::setw(padding + 1) << "*";
        screen << "\n";
        y++;
        right.gotoxy(x, y);
        screen << "*******";
        screen << "\n";
        x += 10;
    }
    return screen;
}
void Sayi::print(int x, int y){
    for (Basamak* itr = head->next; itr != NULL; itr = itr->next) {
        gotoxy(x, y);
        cout << "*******";
        COORD coord;
        cout << endl;
        coord.X = x;
        coord.Y = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
        cout << "* ";
        string address = address_to_string(itr);
        cout << StringManager::get_last_of_address(address);
        cout << " *";
        cout << endl;
        coord.X = x;
        coord.Y = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
        cout << "*******";
        cout << endl;        
        coord.X = x;
        coord.Y = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
        cout << "*";
        int totalWidth = 4;
        int padding = (totalWidth - 1) / 2 + 1;
        cout << std::setw(padding + 1) << itr->item;
        cout << std::setw(padding + 1) << "*";
        cout << endl;
        coord.X = x;
        coord.Y = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
        cout << "*******";
        cout << endl;
        x += 10;
    }
}
void Sayi::gotoxy(int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
int Sayi::GetConsoleCursorPosition(HANDLE hConsoleOutput){
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition.Y;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return -1;
    }
}
Sayi::~Sayi(){
    clear();	
    delete head;
    delete numberManager;
}