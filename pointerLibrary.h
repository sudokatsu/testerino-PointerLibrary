//
// Created by Kurtis Rios on 3/15/20.
//

#ifndef LABANDPLANE_POINTERLIBRARY_H
#define LABANDPLANE_POINTERLIBRARY_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T oneDPrint(T* columnWalker, T* sizesWalker)
{
    for (int k = 0; k < *sizesWalker; k++)
    {
        cout << *columnWalker << " ";
        columnWalker++;
    }
}

template <typename T>
T twoDPrint(T** twoD, T* sizes)
{
    //walkers and loop for printing integer values in each column array
    T** rowWalker;
    rowWalker = twoD;
    T* columnWalker;
    columnWalker = *rowWalker;
    T* sizesWalker;
    sizesWalker = sizes;

    for (int i = 0; *sizesWalker!=-1; i++)
    {
        oneDPrint(columnWalker, sizesWalker);
        sizesWalker++;
        cout << endl;
        rowWalker++;
        columnWalker = *rowWalker;
    }
}

template <typename T>
bool isValid(T** twoD, T* sizes, int r, int c)
{
    T* sizesWalker;
    bool tempBool = true;

    for (int i = 0; i <= r; i++)
    {
        sizesWalker = sizes;
        sizesWalker += i;
        if ((*sizesWalker) == -1)
        {
            tempBool = false;
        }
    }

    sizesWalker = sizes;
    if (c >= *(sizesWalker+r))
    {
        tempBool = false;
    }

    return tempBool;
}

template <typename T>
T* oneDInit(T *columnWalker, T *sizes)
{
    T* sizesWalker;
    sizesWalker = sizes;

    for (int k = 0; k <= *sizesWalker; k++)
    {
        *columnWalker = 0;
        columnWalker++;
    }
}

template <typename T>
T twoDInit(T** twoD, T* sizes)
{
    //walkers and loop for setting integer values to each column array
    T** rowWalker;
    rowWalker = twoD;
    T* columnWalker;
    columnWalker = *rowWalker;
    T* sizesWalker;
    sizesWalker = sizes;

    for (int i = 0; i <= *sizesWalker; i++)
    {
        oneDInit(columnWalker, sizesWalker);
        sizesWalker++;
        rowWalker++;
        columnWalker = *rowWalker;
    }
}

template <typename T>
T** allocate(T* sizes)
{
    //creating twoD array with 3 rows (last one for exit)
    T** twoD;
    int size;
    size = 7; //this is how many rows there are in the 2d array
    twoD = new T* [size+1];

    //walkers and loop to initialize 'column' arrays within the 2d pointer
    T** walkerOne;
    walkerOne = twoD;
    T* sizesWalker;
    sizesWalker = sizes;

    for (int i = 0; i < size; i++)
    {
        *walkerOne = new T [*sizesWalker];
        walkerOne++;
        sizesWalker++;
    }

    return twoD;
}

template <typename T>
T deallocate(T** twoD, T* sizes)
{
    T** rowWalker;
    rowWalker = twoD;
    T* columnWalker;
    columnWalker = *rowWalker;
    T* sizesWalker;
    sizesWalker = sizes;

    //loop to delete all pointer arrays and set them to null

    for(int i = 0; *sizesWalker != -1; i++)
    {
        delete columnWalker;
        columnWalker = NULL;
        delete rowWalker;
        rowWalker = NULL;
        rowWalker++;
        columnWalker = *rowWalker;
        sizesWalker++;
    }
    //I'm not sure if I should set them to NULL, but I THINK it's working
    //considering print and read no longer run if I call it after invoking
    //this f(). If I don't set them to NULL I get a malloc error that
    //there are pointers left unallocated after being freed.
}

template <typename T>
T write(T** twoD, int r, int c, int key)
{
    T** rowWalker;
    rowWalker = twoD;
    rowWalker+=r;

    T* columnWalker;
    columnWalker = *rowWalker;
    columnWalker+=c;
    *columnWalker = key;
}

template <typename T>
T read(T** twoD, int r, int c)
{
    T** rowWalker;
    rowWalker = twoD;
    rowWalker+=r;

    T* columnWalker;
    columnWalker = *rowWalker;
    columnWalker+=c;

    return *columnWalker;
}

template <typename T>
T get(T** twoD, int r, int c)
{
    T** rowWalker;
    rowWalker = twoD;
    rowWalker+=r;
    T* columnWalker;
    columnWalker = *rowWalker;
    columnWalker+=c;
    return *columnWalker;
}

template <typename T>
bool searchValue(T** twoD, T* sizes, int key)
{
    T** rowWalker;
    rowWalker = twoD;
    T* columnWalker;
    columnWalker = *rowWalker;
    T* sizesWalker;
    sizesWalker = sizes;
    int tempBool = false;

    for (int i = 0; *sizesWalker != -1; i++)
    {
        for (int k = 0; k< *sizesWalker; k++)
        {
            if (*columnWalker == key)
            {
                tempBool = true;
            }
            columnWalker++;
        }
        rowWalker++;
        sizesWalker++;
        columnWalker = *rowWalker;
    }

    return tempBool;
}

template <typename T>
T* makeZero(T** twoD, T* sizes, int key)
{
    T** rowWalker;
    rowWalker = twoD;
    T* columnWalker;
    columnWalker = *rowWalker;
    T* sizesWalker;
    sizesWalker = sizes;

    for (int i = 0; *sizesWalker != -1; i++)
    {
        for (int k = 0; k< *sizesWalker; k++)
        {
            if (*columnWalker == key)
            {
                *columnWalker = 0;
            }
            columnWalker++;
        }
        rowWalker++;
        sizesWalker++;
        columnWalker = *rowWalker;
    }
}


#endif //LABANDPLANE_POINTERLIBRARY_H
