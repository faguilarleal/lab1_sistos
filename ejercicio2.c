#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024  // Tamaño del búfer para leer y escribir

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    // Abrir el archivo de origen en modo lectura
    int fd_origen = open(argv[1], O_RDONLY);
    if (fd_origen == -1) {
        perror("Error al abrir el archivo de origen");
        return 1;
    }

    // Crear el archivo de destino con permisos de escritura
    int fd_destino = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_destino == -1) {
        perror("Error al crear el archivo de destino");
        close(fd_origen);
        return 1;
    }

    // Buffer para la lectura y escritura
    char buffer[BUFFER_SIZE];
    ssize_t bytes_leidos, bytes_escritos;

    // Leer y escribir en bloques de BUFFER_SIZE
    while ((bytes_leidos = read(fd_origen, buffer, BUFFER_SIZE)) > 0) {
        bytes_escritos = write(fd_destino, buffer, bytes_leidos);
        if (bytes_escritos != bytes_leidos) {
            perror("Error al escribir en el archivo de destino");
            close(fd_origen);
            close(fd_destino);
            return 1;
        }
    }

    if (bytes_leidos == -1) {
        perror("Error al leer el archivo de origen");
    }

    // Cerrar archivos
    close(fd_origen);
    close(fd_destino);

    printf("Copia completada con éxito.\n");

    return 0;
}
