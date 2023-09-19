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
void handle_uoxX(char c, va_list list, int *counter);
void print_rot13(const char *str, int *counter);
char *reverse_string(const char *input);
void handle_S(char *s, int *counter);
void print_hex(unsigned int n, char *base, int *counter);

#endif
