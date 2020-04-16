//
// Created by Kurtis Rios on 3/23/20.
//

#ifndef LABANDPLANE_PLANEDEMO_H
#define LABANDPLANE_PLANEDEMO_H

#include <iostream>
#include <iomanip>
#include "pointerLibrary.h"

using namespace std;

void testPlane(bool** seatingChart, bool* rows, char command);
bool reserve(bool** seatingChart, bool* rows, int row, int seat);
bool cancel(bool** seatingChart, bool* rows, int row, int seat);

#endif //LABANDPLANE_PLANEDEMO_H
