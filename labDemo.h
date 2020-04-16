//
// Created by Kurtis Rios on 3/15/20.
//

#ifndef LABANDPLANE_LABDEMO_H
#define LABANDPLANE_LABDEMO_H

#include <iostream>
#include <iomanip>
#include "pointerLibrary.h"

using namespace std;

void testLab(int** labs, int* sizes, char choice);
bool login(int** labs, int* sizes, int lab, int station, int id);
bool logout(int** labs, int* sizes, int id);


#endif //LABANDPLANE_LABDEMO_H
