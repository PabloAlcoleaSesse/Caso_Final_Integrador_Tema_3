//
// Created by Pablo Alcolea Sesse on 23/11/24.
//

// load_script.h

#ifndef LOAD_SCRIPT_H
#define LOAD_SCRIPT_H
#include <string>


// Declaración de la estructura ConsoleBox
struct ConsoleBox
{
    void new_text();
    void set_text(const std::string &text);
};

// Declaración de la variable global consoleBox
extern ConsoleBox* consoleBox;

// Declaración de las funciones
void load_script(const char* filename, bool show_script = false);
void load_script();


#endif // LOAD_SCRIPT_H