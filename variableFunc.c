#include <stdio.h>
#include <stdarg.h> // required for variable input function

double average(int num,...) {   // ellipes as second param indicates this is a variable input
                                // int - total number of arguments passed
    va_list valist;  // va_list - from stdarg.h
    double sum = 0.0;
    int i;

    /* Initialize valist for num number of arguments */
    va_start(valist,num);   // set pointer, valist, to point to the arguments of function average()

    /* access all the arguments (read the data) assigned to valist */
    for(i=0; i < num; i++) {
        sum += va_arg(valist,int);  // interpret arguments as int
    }
}