# _printf

Formatted output conversion C program, a pseudo-recreation
of C standard library function, `printf`.

## Description

`_printf` writes output to `stdout`, according to the specifier
`format`, that specifies how the arguments after it are converted.

### 27/11/2023, the current function DOES NOT accept:
* flag characters
* field width
* precision
* length modifiers

### And only the following conversion specifiers are available:
* `%c`
* `%s`
* `%%`
* `%d`
* `%i`

Prototype: `int _printf(const char *format, ...)`

### Return Value

Upon return, `_printf` returns the number of characters printed,
excluding the terminating null byte characteristic of strings.
Upon encountering an error, the function returns `-1`.

## Authors:

* Efrén Jiménez Mukul <[Efrenjm](https://github.com/Efrenjm)>

* Augusto Chi <[Agenc0](https://github.com/Agenc0)>
