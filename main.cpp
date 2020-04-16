#include <iostream>
#include "pointerLibrary.h"
#include "labDemo.h"
#include "planeDemo.h"

using namespace std;

/*
 * Author: Kurtis Rios
 *
 * Project: Lab & Plane
 *
 * Purpose: Lab allows for a user to login to a set lab room and station
 *          number, and then to logout as well. Plane would allow for
 *          a user to reserve a specific seat within a row on an
 *          airplane, as well as cancel their reservation.
 *
 * Notes: Lab worked perfectly. Plane, not so much. I was not able to
 *          get plane to print, but I think allocate and init were
 *          working since it would spit out blank space where the
 *          matrix should have been. Since this is the case, I was
 *          not able to test Plane.
 */

//main used for Plane
int main() {
    bool** seatingChart;
    bool* rows;
    rows = new int[7] {4, 4, 4, 4, 4, 4, -1};

    seatingChart = allocate<int>(rows);
    twoDInit(seatingChart, rows);

    char command;

    testPlane(seatingChart, rows, command);

}

/*
//main used for Lab
int main() {

    int** labs;
    int* sizes;
    sizes = new int[4] {4, 2, 6, -1};

    labs = allocate<int>(sizes);
    twoDInit(labs, sizes);

    char choice;
    testLab(labs, sizes, choice);

}
*/
