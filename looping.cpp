#include <iostream>

// used to get the sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// loops a string in the console at a given rate
void loop(char* str, double speed);

// rotate all of the letters right
void rotate(char* str);

// print a welcome message
void welcome();

// sequentially print the letters in a string at a given rate
void animate(char *str, double speed);

int main()
{
    welcome();

    char str[] = "Hello, user ";
    loop(str, 1);
}

void loop(char *str, double speed) {
    while (true) {
        printf("\033[s"); // save the current cursor position
        printf("%s", str); // print the string
        printf("\033[u"); // go back to the saved position

        rotate(str); // rotate all of the letters in the string
    
        Sleep(100 / speed); // wait for the proper amount of time, according to the speed
    }
}

void rotate(char* str) {
    char first = str[0];
    for (int i = 0; i < strlen(str) - 1; i++) {
        str[i] = str[i + 1];
    }
    str[strlen(str) - 1] = first;
}

void welcome() {
    char welcome[] = "Starting loop!\n";
    char three[] = "3...\n";
    char two[] = "2...\n";
    char one[] = "1...\n";

    animate(welcome, 0.3);
    animate(three, 0.3);
    animate(two, 0.3);
    animate(one, 0.3);
}

void animate(char* str, double speed) {
    for (int i = 0; i < strlen(str); i++) {
        Sleep(100 / speed);
        printf("%c", str[i]);
    }
}