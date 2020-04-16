//
// Created by Kurtis Rios on 3/15/20.
//

#include <iostream>
#include "labDemo.h"

using namespace std;

//logs into seat only if seat is open, you provide a valid ID
//and valid lab/station numbers
bool login(int** labs, int* sizes, int lab, int station, int id)
{
    if (isValid(labs, sizes, lab, station) == true)
    {
        if (read(labs, lab, station) > 0)
        {
            return false;
        }
        else
        {
            write(labs, lab, station, id);
            return true;
        }
    }
    else if (isValid(labs, sizes, lab, station) == false)
    {
        return false;
    }
}

//logs out of any/all seats only if provided with valid ID
bool logout(int** labs, int* sizes, int id)
{
    int tempBool = true;

    if (id > 0)
    {
        if (searchValue(labs, sizes, id) == true)
        {
            makeZero(labs, sizes, id);
        }
        else if (searchValue(labs, sizes, id) == false)
        {
            tempBool = false;
        }
    }
    else
    {
        tempBool = false;
    }

    return tempBool;
}


void testLab(int** labs, int* sizes, char choice)
{
    int id, lab, station;

    do
    {
        cout << "Log[i]n         Log[o]ut        E[x]it" << endl;
        cout << "======================================" << endl;
        cin >> choice;

        switch (choice) {
            case 'i':
            case 'I':
            {
                twoDPrint(labs, sizes);

                cout << "------------LOG IN------------" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "Lab: ";
                cin >> lab;
                cout << "Station: ";
                cin >> station;

                station-=1;
                lab-=1;

                if (login(labs, sizes, lab, station, id) == true)
                {
                    cout << "You are logged in at lab: " << lab+1
                    << " station: " << station+1 << endl;
                    cout << endl;
                    twoDPrint(labs, sizes);
                }
                else if (login(labs, sizes, lab, station, id) == false)
                {
                    cout << "Login unsuccesful." << endl;
                    cout << endl;
                }
                break;
            }
            case 'o':
            case 'O':
            {
                cout << "------------LOG OUT------------" << endl;
                twoDPrint(labs, sizes);
                cout << "ID: " << endl;
                cin >> id;

                if (logout(labs, sizes, id) == true)
                {
                    cout << "Logout was successful." << endl;
                }
                else
                {
                    cout << "You are not logged in. ID: " << id << endl;
                }
                twoDPrint(labs, sizes);
                break;
            }
            case 'x':
            case 'X':
            {
                cout << "Exited." << endl;
                abort();
            }
            default:
            {
                cout << "Please choose again." << endl;
                cin >> choice;
            }
        }
    } while (choice != 'x' or choice != 'X');
}
