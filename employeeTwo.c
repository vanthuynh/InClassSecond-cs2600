#include <string.h>
#include "employee.h"

//NOTE: 5 functions have been defined below

//ptr - points to table to be searched
//tableSize - size of the table
//targetPtr - points to value that will be searched for in table
//functionPtr - points to a comparison function below and will perform the associated check


//What does setting a function to static do? --> ANSWER: means it can only be used in this file
//functionPtr is the address of the function just use the name
//()(The second set of parentheses is the arguments of the function call)
// void * pointer can point to any type of data (this way we can determine later on what the data type be)
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