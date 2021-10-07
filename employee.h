#include <stdio.h>
#include <stddef.h>

typedef struct {
    long number;    // 4 bytes
    char *name;     // address of memory - 4 bytes
    char *phone;    // 4 bytes
    double salary;  // 8 bytes
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;

/* MEANING:
            PtrToConstEmployee: just a variable name
            Employee *PtrToConstEmployee: a pointer of Employee type
            const: once I initialize its value, I cannot change it
*/