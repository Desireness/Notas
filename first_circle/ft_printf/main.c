#include <stdio.h>
#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...);

int main(void)
{
    // Variables útiles
    int x = 42;
    int *pointer = &x;
    int neg = -42;
    unsigned int u = 4294967295; // UINT_MAX
    char c = 'A';
    char *str = "Hola, mundo!";
    char *null_str = NULL;
    int *null_pointer = NULL;

    // Prueba %c (carácter)
    printf("Carácter (printf): [%c]\n", c);
    ft_printf("Carácter (ft_printf): [%c]\n\n", c);

    // Prueba %s (string)
    printf("String (printf): [%s]\n", str);
    ft_printf("String (ft_printf): [%s]\n\n", str);

    // Prueba %s con string nula
    printf("String nula (printf): [%s]\n", null_str);
    ft_printf("String nula (ft_printf): [%s]\n\n", null_str);

    // Prueba %p (puntero)
    printf("Puntero (printf): [%p]\n", (void *)pointer);
    ft_printf("Puntero (ft_printf): [%p]\n\n", (void *)pointer);

    // Prueba %p con puntero nulo
    printf("Puntero nulo (printf): [%p]\n", (void *)null_pointer);
    ft_printf("Puntero nulo (ft_printf): [%p]\n\n", (void *)null_pointer);

    // Prueba %d (entero decimal)
    printf("Entero (printf): [%d]\n", neg);
    ft_printf("Entero (ft_printf): [%d]\n\n", neg);

    // Prueba %d con INT_MIN
    printf("INT_MIN (printf): [%d]\n", INT_MIN);
    ft_printf("INT_MIN (ft_printf): [%d]\n\n", INT_MIN);

    // Prueba %i (entero)
    printf("Entero (%%i) (printf): [%i]\n", x);
    ft_printf("Entero (%%i) (ft_printf): [%i]\n\n", x);

    // Prueba %u (entero sin signo)
    printf("Entero sin signo (printf): [%u]\n", u);
    ft_printf("Entero sin signo (ft_printf): [%u]\n\n", u);

    // Prueba %x (hexadecimal en minúsculas)
    printf("Hexadecimal (%%x) (printf): [%x]\n", x);
    ft_printf("Hexadecimal (%%x) (ft_printf): [%x]\n\n", x);

    // Prueba %X (hexadecimal en mayúsculas)
    printf("Hexadecimal (%%X) (printf): [%X]\n", x);
    ft_printf("Hexadecimal (%%X) (ft_printf): [%X]\n\n", x);

    // Prueba %% (símbolo de porcentaje)
    printf("Porcentaje (printf): [%%]\n");
    ft_printf("Porcentaje (ft_printf): [%%]\n\n");

    // Prueba con múltiples especificadores
    printf("Múltiples (printf): [%c, %s, %d, %i, %u, %x, %X, %%]\n", c, str, neg, x, u, x, x);
    ft_printf("Múltiples (ft_printf): [%c, %s, %d, %i, %u, %x, %X, %%]\n\n", c, str, neg, x, u, x, x);

    return 0;
}