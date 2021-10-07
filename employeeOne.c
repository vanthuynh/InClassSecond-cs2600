#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;  // ptr will stop traversing the table when it meets endPtr

    for(; ptr < endPtr; ptr++)
    {
        if(ptr->number == targetNumber)
            return (PtrToEmployee) ptr;
    }
    return NULL; 
}
// Essentially the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->name,targetName) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

// compare phone number to search for employee
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char* phoneToFind)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;  // ptr will stop traversing the table when it meets endPtr

    for(; ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->phone,phoneToFind) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL; 
}

// compare salary to search for employee
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double salaryToFind)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {
        if(ptr->salary == salaryToFind)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}