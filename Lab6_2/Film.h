//
//  Film.h
#ifndef Film_h
#define Film_h

#include <stdio.h>
#pragma once
#include "Valid.h"
#include <string>
#include <vector>
//#include <windows.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
class Film : public Valid
{
public:
    Valid v;
    string titel;
    string genre;
    int aparitie_an;
    int nr_likes;
    string trailer;
    vector<Film> vector_filme;
    vector<Film> ListaFilme;
    Film();
    void inserare_film();
    void stergere_film();
    void afisare_filme();
    void modificare_film();
    void Cautare(int option);
    //void openTrailer(string trailer);
    void addToListaFilme(Film it);
    void addToListaFilme2(int option);
    void stergere(int option);
    void Afisare(int option);

};

#endif /* Film_h */
