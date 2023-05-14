#include <iostream>
#include <stdlib.h>
#include <cmath>

FILE* f;
char arg;

using namespace std;

void printFile(char* fileName)
{
    if (fopen_s(&f, fileName, "r") != 0)
        cout << "File does not exist";

    cout << "File elements: " << endl;

    while (fread(&arg, sizeof(arg), 1, f) == 1) {
        if (arg == ' ') {
            cout << endl;
        }
        cout << arg;
    }

    cout << "\n\n";

    fclose(f);
}

bool logics(char* fileName, int first_pos, int last_pos) {
    cout << first_pos << " " << last_pos << endl;
    if (fopen_s(&f, fileName, "r") != 0)
        cout << "File does not exist";
    while (fread(&arg, sizeof(arg), first_pos, f) == 1) {
        cout << arg;
    }
    return true;
}

int Check_for_symmetry(char* fileName)
{
    int i = 0, maxElement = 0, last_pos = 0, first_pos = 0;
    if (fopen_s(&f, fileName, "r") != 0)
        cout << "File does not exist";

    while (fread(&arg, sizeof(arg), 1, f) == 1) {
        last_pos++;
        if (arg == ' ') {
            logics(fileName, first_pos, last_pos-1);
            first_pos = last_pos;
        }
        i++;
    }
    return maxElement;
}

int main()
{
    char name[20] = "file.dat";
    do {
        int userChoise = 0;

        cout << "MAIN MENU\n1 - Print file\n2 - Check for symmetry \nYour choise: ";
        cin >> userChoise;

        switch (userChoise)
        {

        case 1: {
            printFile(name);
            break;
        }

        case 2: {
            cout << Check_for_symmetry(name) << endl;
            break;
        }

        default: cout << "Wrong mode!" << endl;
        }
    } while (1);

    return 0;
}
