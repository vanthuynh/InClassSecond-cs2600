#include <string.h>
#include <stdlib.h>
#include "employee.h"

Employee EmployeeTable[] =  // array of employee, no need to define the size since we already initialize with 5 employees
{
    {1001l, "Daphne Borromeo",  "909-555-2134", 8.78},//'l' at the end inteprets the number as "long" data type
    {1011l, "Tammy Franklin",   "213-555-1212", 4.50},
    {1140l, "Dorris Perl",      "310-555-1215", 7.80},
    {4011l, "Tony Bobcat",      "909-555-1235", 6.34},
    {5045l, "Brian Height",     "714-555-2749", 8.32},
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);// 160/32 = 5 employees

// Explain padding in gcc compiler. Each member in struct Employee = 8 bytes
// Depends on Compiler used for Memory alignment. All members acan be accessed by incrementing equal distribution
// void main() {
//     printf("%d\n",sizeof(EmployeeTable));
//     printf("%d\n",sizeof(EmployeeTable[0]));
//     printf("%d\n",sizeof(long));
//     printf("%d\n",sizeof(char*));   // I have Intel 64 bit processor --> 8 bytes for address
//     printf("%d\n",sizeof(char*));   // Note this may change on your processor. RPI3--32 bit processor
//     printf("%d\n",sizeof(double));
// }