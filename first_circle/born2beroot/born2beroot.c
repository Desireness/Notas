/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born2beroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:19:46 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/10 13:14:59 by rauizqui         ###   ########.fr       */
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


Para obtener el espacio total utilizaremos un comando muy parecido. Las únicas diferencias serán que los valores 
que sumaremos serán los $2 en vez de $3 y la otra diferencia es que en el subject aparece el tamaño total en Gb así
que como el resultado de la suma nos da el número en Mb debemos transformarlo a Gb, para ello debemos dividir el
número entre 1024 y quitar los decimales.

	-> df -m | grep "/dev" | grep -v "/boot" | awk '{memory_use += $3} END {printf ("%.0f Gb\n", memory_use / 1024)}'

Por último, debemos mostrar un porcentaje de la memoria usada. Para ello, de nuevo, utilizaremos un comando muy parecido 
a los dos anteriores. Lo único que cambiaremos es que combinaremos los dos comandos anteriores para tener dos variables, 
una que representa la memoria usada y la otra la total. Hecho esto haremos una operación para conseguir el tanto por ciento 
use/total*100 y el resultado de esta operación lo printaremos como aparece en el subject, entre paréntesis y con el símbolo % 
al final. El comando final es este: 

	->df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}'. 	

____________________________________________________________________________________


Porcentaje del uso del CPU

Para poder ver el porcentaje de uso de CPU haremos uso del comando vmstat. Este muestra estadísticas del sistema, permitiendo 
obtener un detalle general de los procesos, uso de memoria, actividad de CPU, estado del sistema, etc. Podríamos poner si ninguna 
opción, pero en mi caso pondré un intervalo de segundos de 1 a 4. También daremos uso del comando tail -1, que este lo que nos va
a permitir es que solo produzca el output la última línea, entonces de las 4 generadas solo se printará la última. Por último, solo 
printaremos la palabra 15 que es el uso de memoria disponible. El comando entero es el siguiente: 

	->vmstat 1 4 | tail -1 | awk '{print $15}'. 
	
El resultado de este comando solo es una parte del resultado final, ya que todavía hay que hacer alguna operación en el script para que quede bien. 
Lo que habría que hacer es a 100 restarle la cantidad que nos ha devuelto nuestro comando, el resultado de esa operación lo printaremos con un decimal 
y un % al final y ya estaría hecha la operación.

____________________________________________________________________________________

Ultimo reinicio

Para ver la fecha y hora de nuestro último reinicio haremos uso del comando who con el flag -b, ya que con ese flag nos mostrará por pantalla el tiempo del 
último arranque del sistema. Como ya nos ha pasado anteriormente, nos muestra más información de la que deseamos, así que filtraremos y solo mostraremos lo 
que nos interesa, para ello haremos uso del comando awk y compararemos si la primera palabra de una línea es "system" se printará por pantalla la tercera palabra 
de esa línea, un espacio y la cuarta palabra. El comando entero sería el siguiente: 

	->who -b | awk '$1 == "system" {print $3 " " $4}'

____________________________________________________________________________________

Uso LVM

Para checkear si LVM está activo o no haremos uso del comando lsblk, este nos muestra información de todos los 
dispositivos de bloque (discos duros, SSD, memorias, etc.) entre toda la información que proporciona podemos ver
lvm en el tipo de gestor. Para este comando haremos un if, ya que o printaremos Yes o No. Básicamente la 
condición que buscamos será contar el número de líneas en las que aparece "lvm" y si hay más de 0 printamos Yes, 
si hay 0 se printará No. Todo el comando sería: 

	->if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi


____________________________________________________________________________________

Conexiones TCP



Para mirar el número de conexiones TCP establecidas. Utilizaremos el comando ss sustituyendo al ya obsoleto netstat. 
Filtraremos con el flag -ta para que solo se muestren las conexiones TCP. Por último haremos un grep para ver las que 
están establecidas, ya que también hay solo de escucha y cerraremos con wc
-l para que cuente el número de líneas. El comando queda tal que así: 

	->ss -ta | grep ESTAB | wc -l.

____________________________________________________________________________________

Numero de usuarios:

Daremos uso del comando users que nos mostrará el nombre de los usuarios que hay, sabiendo esto, 
pondremos wc -w para que cuente la cantidad de palabras que hay en la salida del comando. El comando 
entero queda así 

	->users | wc -w.

____________________________________________________________________________________

Dirección IP y MAC 

Para obtener la dirección del host haremos uso del comando hostname -I y para obtener la MAC haremos uso del comando 
ip link que se utiliza para mostrar o modificar las interfaces de red. Como aparecen más de una interfaz, IPs etc. 
Utilizaremos el comando grep para buscar lo que deseamos y así poder printar por pantalla solo lo que nos piden. Para 
ello pondremos 

	->ip link | grep "link/ether" | awk '{print $2}' y de esta manera solo printaremos la MAC.

____________________________________________________________________________________

Número de comandos ejectuados con sudo

Para poder obtener el número de comandos que son ejecutados con sudo haremos uso del comando journalctl que este es una 
herramienta que se encarga de recopilar y administrar los registros del sistema. Acto seguido pondremos _COMM=sudo par 
así filtrar las entradas especificando su ruta. En nuestro ponemos _COMM , ya que hace referencia a un script ejecutable. 
Una vez tengamos filtrada la búsqueda y solo aparezcan los registros de sudo todavía deberemos filtrar un poco más, ya que 
cuando inicias o cierras sesión de root también aparece en el registro, entonces para terminar de filtrar pondremos un grep 
COMMAND y asi solo aparecerán las líneas de comandos. Por último pondremos wc -l para que asi nos salgan enumeradas las líneas. 
El comando entero es el siguiente: 

	->journalctl _COMM=sudo | grep COMMAND | wc -l). 
	
Para comprobar que funcione correctamente podemos correr el comando en el terminal, poner un comando que incluya sudo y 
volver a correr el comando y deberá incrementar el número de ejecuciones de sudo.


#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
