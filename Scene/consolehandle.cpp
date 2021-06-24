#include <string>
#include <windows.h>

using namespace std;

void color(int color){
    HANDLE stdhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(stdhandle, color);
}
void gotoxy(int x, int y){
    HANDLE stdhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(stdhandle, c);
}


#define MAX_CONTROL_ARRAY 5
class Menu{
    // MenuItem items[MAX_CONTROL_ARRAY];
    int currentFocused;
    
    Menu(){
        
    }
};

class MenuItem{
public:
    string context;
    bool isSelected;
    
    MenuItem(string context){
        this->context = context;
    }
};