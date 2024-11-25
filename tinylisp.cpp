//
// Created by Pablo Alcolea Sesse on 23/11/24.
//

// load_script.cpp

#include <iostream>
#include <string>
#include <cstdio>
#include "tinylisp.h"

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox {
    void new_text() {/*...*/}
    void set_text(const string& text) { cout << text << endl; }
};

ConsoleBox* consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script) {
    string script;
    FILE* f = nullptr;

    try {
        f = fopen(filename, "rb");
        if (!f) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        char buf[4001];
        size_t c;
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = '\0';
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
            cout << "\033[0m";
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (...) {
        cerr << "Error: An exception occurred while reading the file" << endl;
        if (f)
            fclose(f);
    }
}

void load_script() {
    char filename[500];
    cout << "Enter the file name: ";
    cin.getline(filename, 500);
    load_script(filename, true);
}