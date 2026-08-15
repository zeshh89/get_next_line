*This project has been created as part of the 42 curriculum by jose-an2*

# Get Next Line

## 📄 Descripción

`get_next_line` es una función que lee un fichero (o la entrada estándar) línea a línea, sin importar el tamaño del buffer de lectura (`BUFFER_SIZE`) ni el tamaño de las líneas del fichero. El objetivo del proyecto es entender el uso de **variables estáticas** en C, para poder "recordar" el estado de la lectura entre llamadas sucesivas a la función.

```c
char *get_next_line(int fd);
```

- Devuelve la línea leída (incluyendo el `\n` final, salvo en la última línea si el fichero no termina en salto de línea).
- Devuelve `NULL` cuando ya no queda nada por leer o si ocurre un error.

## ⚙️ Instrucciones

Clona el repositorio y compila indicando el tamaño de buffer que quieras probar:

```bash
git clone <git@github.com:zeshh89/get_next_line.git>
cd get_next_line
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Ejemplo de uso básico:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

También funciona leyendo directamente de la entrada estándar (`fd = 0`).

## 🧠 Algoritmo y justificación

La función mantiene, entre llamadas, un **buffer estático** por cada file descriptor que va acumulando lo leído tras cada `read()`. En cada llamada:

1. Si el buffer estático ya contiene un `\n`, se extrae la línea hasta ese punto sin necesidad de leer nada nuevo.
2. Si no lo contiene, se sigue leyendo en bloques de `BUFFER_SIZE` bytes y concatenando al buffer hasta encontrar un `\n` o llegar a fin de fichero.
3. Se devuelve la línea encontrada y se conserva en el buffer estático el resto (lo que venga después del `\n`) para la siguiente llamada.

Esta estrategia evita leer el fichero completo de una sola vez (lo cual sería ineficiente en memoria para ficheros grandes) y funciona igual de bien con buffers muy pequeños (`BUFFER_SIZE=1`) que con buffers muy grandes, ya que el tamaño de lectura y el tamaño de línea son completamente independientes.

## 📚 Recursos

- `man 2 read`
- Documentación sobre variables estáticas en C (ISO C99, sección sobre `static storage duration`)
- **Uso de IA:** consulté a un asistente de IA para entender mejor la diferencia entre `static` a nivel de función y variables globales (prohibidas en este proyecto), y para pensar casos de test con `BUFFER_SIZE` extremos (1 y valores muy grandes). El código de la función y su lógica de gestión del buffer los desarrollé yo mismo.
