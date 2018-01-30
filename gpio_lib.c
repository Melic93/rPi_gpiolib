/****************************************
 *
 * Author: Víctor Fernández Melic
 * Date last update: 30 - Jan - 2018
 * 
 * File: gpio_lib.h
 * Coms: "gpio_lib" is small library to
 *		 easy handle Raspberry Pi GPIO 
 *
 ***************************************/

#include "gpio_lib.h"

int exportGpio (char *gpioNum)
{
	int error = 0;
	int fd;

	if ((fd = open(BASE_ROUTE"/export", O_RDWR | O_TRUNC)) < 0) { error = -1; }
	if((write(fd, gpioNum, strlen(gpioNum))) < 0) { error = -1;}
	close(fd);

	return error;
}

int unexportGpio (char *gpioNum)
{
	int error = 0;
	int fd;

	if ((fd = open(BASE_ROUTE"/unexport", O_RDWR | O_TRUNC)) < 0) { error = -1; }
	if((write(fd, gpioNum, strlen(gpioNum))) < 0) { error = -1; }
	close(fd);

	return error;
}

int setDirection (char *gpioNum, char* dir)
{
	int error = 0;
	int fd;
	char route[MAX_SZ] = BASE_ROUTE"/gpio";

	strcat(route, gpioNum);
	strcat(route, "/direction");

	if ((fd = open(route, O_RDWR | O_TRUNC)) < 0) { error = -1; }
	if((write(fd, dir, strlen(dir))) < 0) { error = -1; }
	close(fd);

	return error;
}

int setValue (char *gpioNum, char* value)
{
	int error = 0;
	int fd;
	char route[MAX_SZ] = BASE_ROUTE"/gpio";

	strcat(route, gpioNum);
	strcat(route, "/value");

	if ((fd = open(route, O_RDWR | O_TRUNC)) < 0) { error = -1; }
	if((write(fd, value, strlen(value))) < 0) { error = -1; }
	close(fd);

	return error;
}

int readValue (char *gpioNum, char *value)
{
	int error = 0;
	int fd;
	char route[MAX_SZ] = BASE_ROUTE"/gpio";

	strcat(route, gpioNum);
	strcat(route, "/value");

	if ((fd = open(route, O_RDWR | O_TRUNC)) < 0) { error = -1; }
	if((read(fd, value, 1) < 0)) { error = -1; }
	close(fd);

	return error;
}
