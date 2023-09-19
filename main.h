#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void _putchar(char c, int *counter);
void print_string(char *str, int *counter);
void print_int(int num, int *counter);
void print_binary(unsigned int num, int *counter);
void print_address(unsigned long n, int *counter);

#endif
