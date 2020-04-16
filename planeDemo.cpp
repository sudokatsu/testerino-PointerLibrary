//
// Created by Kurtis Rios on 3/23/20.
//

#include <iostream>
#include <iomanip>
#include "planeDemo.h"
#include "pointerLibrary.h"

using namespace std;

bool reserve(bool** seatingChart, bool* rows, int row, int seat)
{
    int reservationMarker = 1;
    if (isValid(seatingChart, rows, row, seat))
    {
        if (read(seatingChart, row, seat) == 0)
        {
            write(seatingChart, row, seat, reservationMarker);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (!isValid(seatingChart, rows, row, seat))
    {
        return false;
    }
}



bool cancel(bool** seatingChart, bool* rows, int row, int seat)
{
    int temp = get(seatingChart, row, seat);
    makeZero(seatingChart, rows, temp);
}


void printMenu(bool** seatingChart, bool* rows)
{
    cout << "======================================" << endl;
    twoDPrint(seatingChart, rows);
    cout << "Please choose a row and a seat:" << endl;
}

void testPlane(bool** seatingChart, bool* rows, char command)
{
    int row, seat;

    do
    {
        cout << "What would you like to do?" << endl;
        cout << "[R]eserve  [C]ancel  E[x]it" << endl;
        cin >> command;

        switch(command)
        {
            case 'R':
            case 'r':

                printMenu(seatingChart, rows);
                cin >> row >> seat;

                if (reserve(seatingChart, rows, row, seat))
                {
                    cout << "You are reserved at row: " << row
                         << " seat: " << seat << endl;
                    cout << endl;
                    twoDPrint(seatingChart, rows);
                }
                else if (!reserve(seatingChart, rows, row, seat))
                {
                    cout << "Reservation unsuccessful." << endl;
                    cout << endl;
                }

                break;
            case 'C':
            case 'c':
                printMenu(seatingChart, rows);
                cin >> row >> seat;
                cancel(seatingChart, rows, row, seat);
                break;
            case 'X':
            case 'x':
                cout << "Exiting application.";
                abort();
                break;
            default:
                cout << "Please choose again: " << endl;
                cin >> command;
        }

    } while(command != 'x' or command != 'X');

}
