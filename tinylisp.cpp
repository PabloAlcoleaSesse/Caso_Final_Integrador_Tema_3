//
// Created by Pablo Alcolea Sesse on 23/11/24.
//

// load_script.cpp

#include "tinylisp.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Suponemos que estas estructuras ya están definidas en tu proyecto
struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};



ConsoleBox *consoleBox = new ConsoleBox; // Inicialización de consoleBox

void load_script(const char* filename, bool show_script = false)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error: No se pudo abrir el archivo '" << filename << "'." << endl;
        return;
    }

    // Leer todo el contenido del archivo en un string
    string script_content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    if (file.fail() && !file.eof())
    {
        cerr << "Error: Se produjo un error al leer el archivo." << endl;
        return;
    }

    if (show_script)
    {
        cout << ColorConsole::fg_blue << ColorConsole::bg_white;
        cout << script_content << endl;
    }

    consoleBox->new_text();
    consoleBox->set_text(script_content);
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    getline(cin, filename);

    if (filename.empty())
    {
        cerr << "Error: El nombre del archivo no puede estar vacío." << endl;
        return;
    }

    load_script(filename.c_str(), true);
}