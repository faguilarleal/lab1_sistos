# lab1_sistos

Para este ejercicio en lugar de hacer una máquina virtual se trabajo con Docker.  
1. Se construyó una imagen y container de Docker para poder utilizar linux desde mi computadora Windows. Se modificó el kernel/fork.c y se agrega el system call del Hello World.
2. Luego se edita el syscall.h y syscall_64.tbl para agregar la llamada al sistema creada en el paso anterior
3. Se ejecuta el kernel
4. Luego se crea un archivo .asm con el siguiente codigo:
```assembly
global _start

section .text

_start:
mov rax, 548
syscall

jmp $
```        
5. Se ejecuta y por medio de Docker se copian lso archivos init.cpio y bzImage a mi computadora
6. Luego se corre esta instrucción y listo

![Imagen de WhatsApp 2025-02-08 a las 23 10 09_303ae95b](https://github.com/user-attachments/assets/51366f58-d1ff-458e-bbfd-68e3fa775ee6)


Se siguió este tutorial para la creación del system call https://www.youtube.com/watch?v=Kn6D7sH7Fts    
Se siguó este tutorial para la instalación de qemu en windows https://www.youtube.com/watch?v=HywXtRz0URE
