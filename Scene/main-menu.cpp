#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
    int counter = 3;
    char key;

    for(int i=0;;)
    {


        gotoxy(10,5);
        color(Set[0]);
        cout<<"1. Menu";

        gotoxy(10,6);
        color(Set[1]);
        cout<<"2. Help";

        gotoxy(10,7);
        color(Set[2]);
        cout<<"3. Exit";

        gotoxy(10,8);
        color(Set[3]);
        cout<<"4. Extra_1";

        gotoxy(10,9);
        color(Set[4]);
        cout<<"5. Extra_2";

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 5))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 4))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                cout<<"Menu 1 is Open";
            }
            if(counter == 2)
            {
                cout<<"Menu 2 is Open";
            }
            if(counter == 3)
            {
                cout<<"Menu 3 is Open";
            }
            if(counter == 4)
            {
                cout<<"Menu 4 is Open";
            }
            if(counter == 5)
            {
                cout<<"Menu 5 is Open";
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if(counter == 1)
        {
            Set[0] = 12;
        }
        if(counter == 2)
        {
            Set[1] = 12;
        }
        if(counter == 3)
        {
            Set[2] = 12;
        }
        if(counter == 4)
        {
            Set[3] = 12;
        }
        if(counter == 5)
        {
            Set[4] = 12;
        }


    }
}
