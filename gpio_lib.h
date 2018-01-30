/****************************************
 *
 * Author: Víctor Fernández Melic
 * Date last update: 29 - Jan - 2018
 * 
 * File: gpio_lib.h
 * Coms: Headers file of "gpio_lib" for
 *		 Raspberry Pi control of GPIO 
 *
 ***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_SZ 50
#define BASE_ROUTE "/sys/class/gpio"

/* Export GPIO @gpioNum */
/* Returns 0 if everything is ok. Returns -1 on error */
/* Returns -1 if already exported */
int exportGpio (char *gpioNum);

/* Unexport GPIO @gpioNum */
/* Returns 0 if everything is ok. Returns -1 on error */
/* Returns -1 if nothing to unexport */
int unexportGpio (char *gpioNum);

/* Set direction @dir to GPIO @gpioNum */
/* Returns 0 if everything is ok. Returns -1 on error */
/* @dir := in/out */
int setDirection (char *gpioNum, char* dir);

/* Set value @value to GPIO @gpioNum */
/* Returns 0 if everything is ok. Returns -1 on error */
/* @value := 0/1 */
int setValue (char *gpioNum, char* value);

/* Read value of GPIO @gpioNum and stores its value in @value */
/* Returns 0 if everything is ok. Returns -1 on error */
int readValue (char *gpioNum, char *value);
