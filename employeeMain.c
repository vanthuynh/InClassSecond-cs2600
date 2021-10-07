// gcc employeeMain.c employeeTable.c employeeOne.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char* nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char* phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries,"Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n",matchPtr - EmployeeTable); // 96 bytes/32 = 3
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Example phone number found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries,"714-555-2749");
    if(matchPtr != NULL)
        printf("Employee with phone# 714-555-2749 is in record %d\n",matchPtr - EmployeeTable); // 96 bytes/32 = 3
    else
        printf("Employee with phone# 714-555-2749 is NOT found in the record\n");
    // Example phone number NOT found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries,"714-007-7777");
    if(matchPtr != NULL)
        printf("Employee with phone# 714-007-7777 is in record %d\n",matchPtr - EmployeeTable); // 96 bytes/32 = 3
    else
        printf("Employee with phone# 714-007-7777 is NOT found in the record\n");
    // Example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if(matchPtr != NULL)
        printf("Employee with salary 8.32 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 8.32 is NOT found in the record\n");
    // Example salary NOT found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.0);
    if(matchPtr != NULL)
        printf("Employee with salary 10.0 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 10.0 is NOT found in the record\n");
    return EXIT_SUCCESS;
}