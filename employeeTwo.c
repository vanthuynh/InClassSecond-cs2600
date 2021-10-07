#include <string.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, 
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++)
        if((*functionPtr)(targetPtr,ptr) == 0) //compareEmployeeNumber(&1045, TableRow)
            return (PtrToEmployee) ptr;
    return NULL;
}

//The functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    // meanings: typecast targetPtr as a long pointer, then dereference it
    return * (long *) targetPtr != tableValuePtr->number; // const void *targetPtr ==> typecast as int pointer
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name); // const void *targetPtr ==> typecase as character
}




// These are called wrappers. These funcitons are what you will use in your main!!!
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{
    // here we pass the address(&) of number because we are using a void pointer type
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name)
{
    // here we already passing the address with char* name so we don't have to use &
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}