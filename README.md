# Game Completion Time Advisor

Proyecto final del curso de Programación Estructurada – C++  
Universidad Interamericana de Puerto Rico – 2025  

## Integrantes del equipo
- Naesha Perez – Parte 1: Módulo de géneros de videojuegos  
- Emanuel Vega – Parte 2: Manejo de archivos (guardar/cargar), menú principal y organización  
- Angel Pastor – Parte 3: Cálculo de horas estimadas y validaciones  

## ¿De qué trata el programa?

Este programa permite:
- Ver diferentes géneros de videojuegos  
- Mostrar una lista de juegos con sus horas base  
- Agregar nuevos juegos manualmente  
- Guardar y cargar juegos usando archivos  
- Calcular cuántas horas toma completar un juego según el tipo de jugador:
  - Casual  
  - Normal  
  - Explorador  
  - Completista  

## ¿Qué problema resuelve?

Ayuda al usuario a estimar su tiempo de juego dependiendo de cómo le gusta jugar.  
También permite guardar información de forma persistente usando archivos .txt

## Librerías utilizadas

- <iostream> – Entrada y salida de datos  
- <string> – Manejo de texto  
- <fstream> – Lectura/escritura de archivos  
- <iomanip> – Formato de impresión  

## Cómo ejecutar el programa

Compilar:

Ejecutar:


## Estructura del proyecto

- **main.cpp** – Contiene todo el código del programa  
- **juegos_guardados.txt** – Archivo donde se guardan los juegos añadidos  

## Principales funciones del programa

- `moduloGeneros()` – Muestra los géneros y una descripción  
- `guardarJuegos()` – Guarda los juegos en archivo  
- `cargarJuegos()` – Carga los juegos del archivo  
- `calcularHoras()` – Calcula el tiempo estimado según el tipo de jugador  
- `mostrarJuegos()` – Muestra todos los juegos registrados  
- `agregarJuego()` – Añade nuevos juegos  
- `mostrarPromedio()` – Calcula el promedio de horas base  

## Version History

v1.0 – Versión inicial del proyecto  
v1.1 – Se añadió manejo de archivos  
v1.2 – Organización del menú principal  

## License

Proyecto creado únicamente para uso académico del curso de C++.  
No se permite el uso comercial.

## Fuentes de referencia (APA)

OpenAI. (2025). Asistencia para estructura del proyecto. Recuperado de https://chat.openai.com  
cplusplus.com. (2025). Documentación estándar de C++. Recuperado de https://cplusplus.com  
en.cppreference.com. (2025). Librerías de C++. Recuperado de https://en.cppreference.com  

