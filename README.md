# ft_printf

This project was about recreating the libc's printf function in my own way.

The recreated printf function was supposed to be called ft_printf.

A challenge was to create a well structured and readable code to be able to extend the ft_printf function with e.g other conversion characters if needed or flags. 

We also have a norm that our code need to go through, e.g. our functions cannot be longer that 25 rows, every row need to start with tabs or our rows shouldn't be too long. This will keep our code much more neat.

Our function should also be coded in such a manner that we do not get segmentation faults, bus error or double free.

Allowed external functions: write, malloc, free, exit and the functions found in man stdarg.h (va_list, va_start, va_arg, va_end, va_copy).

Our ft_printf function should handle conversions csp, diouxx (including ll, l, hh, h flags) and f (including l, L).

We should also handle this exception %%.

Flags to be handled are #0-+ and space, precision and space should also be handled.

During this project I learned more about stack memory, the stackpointer and how variadic functions/macros work together with the stack memory (va_list, va_start, va_arg, va_end).

# How to

Compile the libftprint.a by running  ```make```

The main.c can be used together with the library for testing purposes. 
