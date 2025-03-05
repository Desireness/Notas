/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born2beroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:19:46 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/05 14:12:51 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Root Password: 42madrid;
New User: rauizqui;
    ->Nueva contraseña: 42madrid;

Encryption passphrase: 42madrid;

Volume group name: LVM Group;
    -> Se modifica el puerto 22 ->4242;
	-> instalamos el ufw;

PASS MAX DAYS 30 -> Tiempo expiración contraseña
PASS MIN DAYS 30 -> Num minn de dias permitido antes de modificar una constraseña

____________________________________________________________________________________

Comandos para la política de contraseñas fuerte:

minlen = 10 -> cantidad minima de caracteres;

ucredit= -1 -> min una letra mayus, -1 por que debe contener min un car, siendo 
positivo sera maximo un caracter;

dcredit=-1 -> Como mínimo debe contener un dígito.

lcredit = -1 -> min 1 minuscula;

maxrepeat=3 -> No puede tener más de 3 veces seguidas el mismo carácter.

reject_username -> No puede contener el nombre del usuario.

difok=7 -> Debe tener al menos 7 caracteres que no sean parte de la antigua contraseña.

enforce_for_root -> Implementaremos esta política para el usuario root.

____________________________________________________________________________________

ver arquitectura: 
	->  uname -a

ver Núcleos físicos:
	-> mirar en /proc/cpuinfo 
	   -> grep "physical id" /proc/cpuinfo | sort -u | wc -l
	   (sort -u elimina duplicados).

ver Núcleos virtuales:
	-> grep processor /proc/cpuinfo | wc -l

ver RAM:
	-> free --mega

		-> free --mega | awk '$1 == "Mem:" {print $3}'
			->free --mega | awk '$1 == "Mem:" {print $2}'
				->para la memoria total.

Ver % mem usada a partir del anterior:

	->free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'
	
_____________________

Memoria del disco:
	-> df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'

Para obtener el espacio total utilizaremos un comando muy parecido. Las únicas diferencias serán que 
los valores que sumaremos serán los $2 en vez de $3 y la otra diferencia es que en el subject aparece el 
tamaño total en Gb así que como el resultado de la suma nos da el número en Mb debemos transformarlo a Gb, 
para ello debemos dividir el número entre 1024 y quitar los decimales.
