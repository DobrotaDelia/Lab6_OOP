
#include "Valid.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int Valid::validare_film(string nume)
{
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    ifstream in("filme.txt", ios::in);
    while (in >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
        if (titel == nume)
            return 0;
    return 1;
}
bool Valid::verificare_nr(int strin) {
    string str = to_string(strin);
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
