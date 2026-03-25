# Práctica 1: Entrada/Salida mediante Interrupciones

**Autores:** Inés Prados y Darío Ortega  
**Asignatura:** Programación de Dispositivos e Interfaz de Hardware (PDIH)  
**Grado:** Ingeniería Informática - UGR

## 1. Objetivos cumplidos
Se ha implementado una librería completa de E/S (`mi_io.c` y `mi_io.h`) utilizando interrupciones de la BIOS (**Int 10h** para vídeo y **Int 16h** para teclado) y de MS-DOS (**Int 21h**).

## 2. Funciones implementadas (Requisitos mínimos)
| Función | Descripción | Interrupción |
| :--- | :--- | :--- |
| `gotoxy()` | Posiciona el cursor en (X,Y) | Int 10h, AH=02h |
| `setcursortype()` | Cambia aspecto del cursor (Invisible, Normal, Grueso) | Int 10h, AH=01h |
| `setvideomode()` | Cambia el modo de vídeo (Texto/Gráfico) | Int 10h, AH=00h |
| `getvideomode()` | Obtiene el modo de vídeo actual | Int 10h, AH=0Fh |
| `textcolor()` | Cambia el color del texto | Manipulación de bits |
| `textbackground()` | Cambia el color de fondo | Manipulación de bits |
| `clrscr()` | Borra la pantalla | Int 10h, AH=06h |
| `cputchar()` | Escribe un carácter con color y avanza cursor | Int 10h, AH=09h |
| `getche()` | Lee tecla con eco en pantalla | Int 21h, AH=01h |
| `pixel()` | Dibuja un píxel en modo gráfico (CGA) | Int 10h, AH=0Ch |

## 3. Ejercicios Extra (Ampliados)
- **Recuadros:** Función `dibujar_recuadro` para interfaces de texto.
- **Modo Gráfico:** Pruebas de dibujo en modo CGA (320x200).
- **ASCII Art:** Representación de un gato amarillo en modo texto.

## 4. Instrucciones de uso
Para compilar y ejecutar en DOSBox:
1. Abrir Borland C (`bc`).
2. Abrir el proyecto `P1.PRJ`.
3. Compilar y ejecutar con `Alt + R`.
