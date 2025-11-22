# _PRINTF PROJECT

This is a custom printf function that replicates some of the features of printf(3). This was completed as part of a group project for Holberton School Australia in Sprint 1- Coding in C. 

# IMPLEMENTED FEATURES

* Characters (%c)
* Strings (%s)
* Decimal integers (%i, %d)
* Binary integers (%b)
* Unsigned decimal integers (%u)
* Octal integers (%o)
* Hexadecimal integers (%x, %X)
* Custom strings (%S)
* Pointer address (%p)
* Hnadle flags for non custom conversion specifiers (+, #)

# REQUIREMENTS

Allowed editors: vi, vim, emacs

Authorized functions and macros:
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

# COMPILATION

All files were compiled on Ubuntu 20.04 LTS

All the .c files with a main.c file are compiled using below:

``
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
``

# HOW TO USE

Please refer to the man_3_printf page 

Example:

```c
int main(void)
{
    int num = 100;
    char *string = "Can we get";
    
    _printf("%s %d%%?\n", string, num);
    return (0);
}

Output:

Can we get 100%?

# TEAM

* Shan 
* Liani
