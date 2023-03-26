Hello, welcome to our first group project, we're replicating the printf() function from the C Standard Library.
Introduction to the project

Project _printf() - Produce output to stdout according to a format described below, similar to the printf() function.

Environment:

    Language: C
    Editor: VIM 8.1.2269
    Compiler: gcc 9.3.0
    Wall -Werror -Wextra -pedantic -std=gnu89
    Style guidelines: Betty style

Project specification:

    Not allowed to use global variables
    No more than 5 functions per file
    All files end with a new line

Specifiers:

    c: character
    s: string
    d or i: signed integer
    %: %

Repository files:

    README.md: this file
    _putchar.c: putchar function
    get_function.c: get_function function
    main.h: header file
    print_char.c: print_char function
    print_digit.c: print_digit function
    print_string.c: print_string function
    printf.c: main function
    man_3_printf: man page
    printf_flowchart.png: flowchart _printf

Compilation:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

Examples:

_printf function examples:

_printf("Character:[%c]\n", 'H');
Output: Character:[H]

_printf("String:[%s]\n", "I am a string !");
Output: String:[I am a string !]

_printf("Decimal: [%d]\n", 10000);
Output: Decimal: [10000]

_printf("Percent: [%%]\n");
Output: Percent: [%]
