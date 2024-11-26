# Caso_Final_Integrador_Tema_3
https://github.com/PabloAlcoleaSesse/Caso_Final_Integrador_Tema_3.git

## Trabajos prácticos

1. Carga de scripts en tiny-lisp
El módulo Labmain.cpp define la función load_script(), que se utiliza para cargar un script en la memoria y aplicarle la coloración sintáctica. Esta función se basa en la librería estándar de C.


Implementa las funciones load_script() y load_script(filename, true) en CLion, de tal manera que puedas abrir y leer archivos de texto. El primer método toma el nombre de un archivo como entrada del usuario, mientras que el segundo muestra el contenido del archivo. Ambos métodos deben cargar el script en la consola.


void load_script(const char* filename, bool show_script = false);
void load_script();
2. Asegurando la robustez del código
Asegúrate de que tu código pueda manejar diferentes tipos de errores de entrada. Esto incluye, pero no se limita a:


El usuario proporciona un nombre de archivo que no existe.
El archivo proporcionado no se puede abrir por alguna razón.
Se produce un error de lectura durante la lectura del archivo.
Para manejar estos y otros errores potenciales, es posible que desees agregar comprobaciones de errores adicionales y manejar los fallos de manera más sofisticada.


# 3. Valoracion de código de Alejandro Abanades Abanades

El codigo maneja bien los errores.
``` cpp

f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "error de apertura de " << filename << endl;
            return;
        }

```
Este bloque de código maneja adecuadamente el caso en el que el archivo no se puede abrir. Si f es nullptr, significa que fopen no pudo abrir el archivo. Esto podría ocurrir porque el archivo no existe, hay problemas de permisos, o el nombre del archivo es incorrecto.

``` cpp

catch (...)
    {
        cerr << "error durante la lectura del archivo" << endl;
        if(f)
            fclose(f);
    }


```
Este bloque es útil para capturar errores genéricos en el proceso de lectura. Sin embargo, catch (...) atrapa cualquier tipo de excepción, lo cual puede dificultar el diagnóstico del problema si no se maneja adecuadamente.

### La utilización de fopen y fread
Estas funciones son válidas pero son parte del lenguaje C, lo cual puede ser considerado obsoleto en programas modernos de C++.
	•	Usar std::ifstream de C++ es más seguro porque:
	•	Es más fácil de usar con std::string y es más idiomático para desarrolladores de C++.
 
 
### Utilización de "namespace std" 
Aunque usar namespace std es práctico porque evita escribir std:: repetidamente, en proyectos grandes puede causar conflictos de nombres.

### Nombres poco encendibles 
Variables como f o c son poco descriptivas y dificultan la comprensión del código.




