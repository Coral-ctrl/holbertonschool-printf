# NAME
_printf - formatted output conversion

# LIBRARY
Standard C library

# SYNOPSIS

#include "main.h"

int _printf((const char *format, ...);

# DESCRIPTION

The function **_printf** outputs to the stdout according to the format string. To reduce the number of times the write function is called, and therefore optimize performance, a local buffer of 1024 characters is used. 

### Format of the format string 
The format string is composed of zero or more directives- ordinary characters (not %) that are copied unchanged to stdout and conversion specifiers that tell **_printf()** how to handle the variadic list of arguments. The **get_printer()** function handles each format specifier in the format string and returns a function pointer to the appropriate function to handle the type defined by the specifier. 

Each function returned by the **get_printer()** function will take the va_list as an argument and use the **_putchar()** function to print to the stdout. All of these fucntions return their length to **_printf()** so the total length can be counted and returned at the end of the **_printf()** function. 

### FLAG CHARACTERS
One or more of the following flag characters may appear after the % character to modify the conversion behavior:

+      A sign (+ or -) should always be placed before a number produced by a signed  conversion.  Applies to d and i conversions.

' '    (a  space) If no sign is going to be written, a blank space is inserted before the value. This flag is ignored if the + flag is present. Applies to d and i conversions.

\#      The value should be converted to an "alternate form". For o conversions, the  first  character of  the  output string is made zero (by prefixing a 0 if it was not zero already). For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.

# CONVERSION SPECIFIERS

Each conversion specifier is introduced by the character % and ends with the conversion specifier. They define the type of conversion to be applied. 

| Conversion Specifier        | Description         |
| :--- | :--- |
| c         | Prints a single character        |
| s         | Prints each character in array until null terminator is reached         |
| S         |         |
| d, i         |         |
| b         | Converts the integer value to its binary representation without leading zeros and prints it         |
| p         | Converts the pointer value (memory address) to hexadecimal and prints it         |
| %         | A '%' character is printed. No argument is converted         |
| u         | Converts the unsigned integer argument to unsigned decimal notation and prints it        |
| o         | Converts the unsigned integer argument to unsigned octal notation and prints it        |
| x         | Converts the unsigned integer argument to unsigned hexadecimal notation (lowercase) and prints
              it        |
| X         | Converts the unsigned integer argument to unsigned hexadecimal notation (uppercase) and prints
              it        |

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
_printf("Custom: %S\n", "Best\nSchool");

Output: "Custom: Best\x0ASchool"
```

### Printing an Integer

```c
_printf("Integer: %d\n", 1024);
_printf("Negative: %i\n", -98);

Output: "Integer: 1024"
Output: "Negative: -98"
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

### Printing an Unsigned Integer

```c
_printf("Unsigned: %u\n", 4294967295);

Output: "Unsigned: 4294967295"
```
### Printing an Octal

```c
_printf("Octal: %o\n", 64);

 Output: "Octal: 100"
```

### Printing Hexadecimal- upper and lower

```c
_printf("Hex lowercase: %x\n", 255);
_printf("Hex uppercase: %X\n", 255);

Output: "Hex lowercase: ff"
Output: "Hex uppercase: FF"
```
# BUGS

No known bugs

# AUTHORS

Written by Liani and Shan

_printf man page
