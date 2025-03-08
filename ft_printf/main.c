#include <stdio.h>
#include "ft_printf.h"

int main()
{   
    int x;
    int *pointer = &x;    
    int neg = -42;
    unsigned int u = 4294967295;

    // Carácter
    printf("printf original: ");
    printf("Hola %c!\n", 'A');
    ft_printf("ft_printf: ");
    ft_printf("Hola %c!\n", 'A');

    // Varias veces el carácter
    printf("\nprintf original: ");
    printf("Caràcter: %c %c %c\n", 'X', 'Y', 'Z');
    ft_printf("ft_printf: ");
    ft_printf("Caràcter: %c %c %c\n", 'X', 'Y', 'Z');

    // Cadena de caracteres
    printf("\nprintf original: ");
    printf("Hola, prueba\n%s", "Prueba1\n");
    ft_printf("ft_printf: ");
    ft_printf("Hola, prueba\n%s", "Prueba1\n");

    // Puntero
    printf("\nprintf original: ");
    printf("XDDDDD\n%p\n", (void *)pointer);
    ft_printf("ft_printf: ");
    ft_printf("XDDDDD\n%p\n", (void *)pointer);

    // Número decimal (d)
    printf("\nprintf original: ");
    printf("Numero (d): %d\n", 10);
    ft_printf("ft_printf: ");
    ft_printf("Numero (d): %d\n", 10);

    // Número entero (i)
    printf("\nprintf original: ");
    printf("Numero (i): %i\n", -10);
    ft_printf("ft_printf: ");
    ft_printf("Numero (i): %i\n", -10);

    // Número negativo (d)
    printf("\nprintf original: ");
    printf("Numero negativo (d): %d\n", neg);
    ft_printf("ft_printf: ");
    ft_printf("Numero negativo (d): %d\n", neg);

    // unsigned (u)
    printf("\nprintf original: ");
    printf("Numero unsigned: %u\n", u);
    ft_printf("ft_printf: ");
    ft_printf("Numero unsigned: %u\n", u);

    // Hexadecimal minúsculas (x)
    printf("\nprintf original: ");
    printf("Hexadecimal (minúsculas): %x\n", 255);
    ft_printf("ft_printf: ");
    ft_printf("Hexadecimal (minúsculas): %x\n", 255);

    // Hexadecimal mayúsculas (X)
    printf("\nprintf original: ");
    printf("Hexadecimal (mayúsculas): %X\n", 255);
    ft_printf("ft_printf: ");
    ft_printf("Hexadecimal (mayúsculas): %X\n", 255);

    // Porcentaje (%%)
    printf("\nprintf original: ");
    printf("Porcentaje: %%\n");
    ft_printf("ft_printf: ");
    ft_printf("Porcentaje: %%\n");

    return (0);
}