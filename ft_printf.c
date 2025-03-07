/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:28:02 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/07 01:43:48 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Primeros pasos en el printf:

lets work on stdarg.h
		-> as the main function, the original printf does not know beforehand how many args
			needs. So this library can make it go through the args in a safe way.

Useful macros

	-> va_list: a variable declaration that is gonna store the args.

	-> va_start(va_list, last_fixed_arg): args initialized, last_fixed_arg is the last 
		known arg before variables.
	
	-> va_arg(va_list, type): Obtains the last arg of the list, returns it with the 
		specified type.

	-> va_end(va_list): End of the args list.


Se necesita cubrir con el identificador %:

> %c Imprime un solo carácter.
> %s Imprime una string (como se define por defecto en C).
> %p El puntero void * dado como argumento se imprime en formato hexadecimal.
> %d Imprime un número decimal (base 10).
> %i Imprime un entero en base 10.
> %u Imprime un número decimal (base 10) sin signo.
> %x Imprime un número hexadecimal (base 16) en minúsculas.
> %X Imprime un número hexadecimal (base 16) en mayúsculas.
> % % para imprimir el símbolo del porcentaje.

	-> De los cuales he cubierto:
		> %c [OK]
		> %s [OK]
		> %p
		> %d
		> %i
		> %u
		> %x 
		> %X
		> %%