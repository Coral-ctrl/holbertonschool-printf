# NAME
_printf

# LIBRARY
main.h

# SYNOPSIS

#include "main.h"
int _printf((const char *format, ...);

# DESCRIPTION

The function **_printf** outputs to the stdout according to the format string. To reduce the number of times the write function is called, and therefore optimize performance, a local buffer of 1024 characters is used. 

### Format of the format string 
The format string is composed of zero or more directives- ordinary characters (not %) that are copied unchanged to stdout and conversion specifiers that tell **_printf** how to handle the variadic list of arguments. The **get_printer** function handles each format specifier in the format string and returns a function pointer to the appropriate function to handle the type defined by the specifier. 

Each function returned by the **get_printer** function will take the va_list as an argument and use the **_putchar** function to print to the stdout. All of these fucntions return their length to **_printf** so the total length can be counted and returned at the end of the **_printf** function. 

# CONVERSION SPECIFIERS

Each conversion specifier is introduced by the character % and ends with the conversion specifier. They define the type of conversion to be applied. 

c
        Prints a single character

s       Prints each character in array until null terminator is reached

S       

d, i    

b       Converts the integer value to its binary representation without leading zeros and prints it 

p       Converts the pointer value (memory address) to hexadecimal and prints it

%       A '%' character is printed. No argument is converted.

u

o

x

X

# RETURN VALUE

On successful return, these functions return the number of bytes printed (excluding the null terminator at the end of strings).

On error, -1 is returned. 


# EXAMPLES

### Printing a Character

```c
_printf("Character: %c\n", 'A');

Output: "Character: A"
```

### Printing a String

```c
_printf("My name is %s!\n", "Bob");

Output: "My name is Bob!"
```

### Printing a Custom String

```c

```

### Printing an Integer

```c

```

### Printing Binary 

```c
_printf("Binary: %b\n", 98);

Output: "Binary: 1100010"
```

### Printing Pointer Address

```c
_printf("Address: %p\n", (void *)0x7ffe637541f0);

Output: "Address: 0x7ffe637541f0"
```

### Printing a Percent Sign

```c
_printf("Precent Sign: %%\n");

Output: "Percent Sign: %"
```


