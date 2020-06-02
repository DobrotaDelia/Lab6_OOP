#include "Film.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <assert.h>
#include "Windows.h" 
#define assert(exp) ((void) 0)
using namespace std;
// default constructor
Film::Film()
{
    titel = "";
    genre = "";
    aparitie_an = 0;
    nr_likes = 0;
    trailer = "";
}
//adding a film, ad the beginnning of a programm meanwhile  creating a list
//inserting a new film as the adminastrator 
void Film::inserare_film()
{
    Valid v;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    cout << "Ce nume are filmul?";
    cin >> titel;
    if (v.validare_film(titel) == 1)
    {
        cout << "Ce gen este filmul?";
        cin >> genre;
        cout << "In ce an a aparut filmul?";
        while (!(cin >> aparitie_an))
        {
            cout << "Eroare:Reintroduceti data! ";
            cin.clear();
            cin.ignore(123, '\n');

        }
        cout << "Care este numarul de like-uri?";
        while (!(cin >> nr_likes))
        {
            cout << "Eroare:Reintroduceti numarul de like-uri! ";
            cin.clear();
            cin.ignore(123, '\n');

        }
        cout << "Care este linkul trailerului?";
        cin >> trailer;
        ofstream out("filme.txt", ios::app);
        out << titel << ' ' << genre << ' ' << aparitie_an << ' ' << nr_likes << ' ' << trailer << endl;
        cout << "Filmul a fost adaugat cu succes";
        out.close();
    }
    else
        cout << "Numele exista deja";
}
void Film::afisare_filme()
{
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    ifstream in("filme.txt", ios::in);
    while (in >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
        cout << titel << " " << genre << " " << aparitie_an << " " << nr_likes << " " << trailer << endl;
}
//deleting a film
void Film::stergere_film()
{
    Valid v;
    vector<Film> aux;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    string nume;
    cout << "Ce filme doriti sa stergeti?";
    cin >> nume;
    ifstream in("filme.txt", ios::in);
    //if the name exists it is possible to delete it
    if (v.validare_film(nume) == 0)
    {
        while (in >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
            if (titel != nume)
            {
                f.titel = titel;
                f.genre = genre;
                f.aparitie_an = aparitie_an;
                f.nr_likes = nr_likes;
                f.trailer = trailer;
                aux.push_back(f);//creating a new vector
            }
        vector_filme = aux;// aux in the  vector v
        ofstream out("filme.txt", ios::out);
        for (const auto& film : vector_filme)
            out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
        cout << "Filmul a fost sters cu succes";
        in.close();
        out.close();
    }
    else
        cout << "Filmul pe care doriti sa-l stergeti nu exista";
}

void Film::modificare_film()
{
    vector<Film> aux;
    Film f;
    Valid v;
    string titel, genre, trailer, nume, tr, gen, t;
    int aparitie_an, nr_likes, an;
    string titlu;
    int m;
    cout << "Ce film doriti sa modificati?" << endl;
    cin >> nume;
    if (v.validare_film(nume) == 0)
    {
        cout << "Alegeti ce doriti sa modificati la acest film:" << endl;
        cout << "1.Titlu" << endl;
        cout << "2.Genul" << endl;
        cout << "3.Anul" << endl;
        cout << "4.Nr Likes" << endl;
        cout << "5.Link trailer" << endl;
        cin >> m;
        ifstream in1("filme.txt", ios::in);
        while (in1 >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
            if (titel != nume)
            {
                f.titel = titel;
                f.genre = genre;
                f.aparitie_an = aparitie_an;
                f.nr_likes = nr_likes;
                f.trailer = trailer;
                aux.push_back(f);//a vector, withouth the filme which we want to delete
            }
            else
            {
                t = titel;
                gen = genre;
                an = aparitie_an;
                nr_likes = nr_likes;
                tr = trailer;
            }
        in1.close();
        ofstream out("filme.txt", ios::out);
        for (const auto& film : aux)
            out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
        out.close();
        ofstream out1("filme.txt", ios::app);
        if (m == 1)
        {
            cout << "Titlu nou:";
            cin >> titlu;
            out1 << titlu << " " << gen << " " << nr_likes << " " << tr;
            cout << "Titlul a fost schimbat!" << endl;

        }
        if (m == 2)
        {
            cout << "Gen nou:";
            cin >> genre;
            out1 << t << " " << genre << " " << nr_likes << " " << tr;
            cout << "Genul a fost schimbat!";
        }
        if (m == 3)
        {
            cout << "An nou:";
            while (!(cin >> aparitie_an))
            {
                cout << "Eroare:Reintroduceti data! ";
                cin.clear();
                cin.ignore(123, '\n');

            }
            out1 << t << " " << gen << " " << aparitie_an << " " << nr_likes << " " << tr;
            cout << "Anul a fost schimbat!";
        }
        if (m == 4)
        {
            cout << "Numar de like-uri nou:";
            while (!(cin >> nr_likes))
            {
                cout << "Eroare:Reintroduceti data! ";
                cin.clear();
                cin.ignore(123, '\n');

            }
            out1 << t << " " << gen << " " << nr_likes << " " << tr;
            cout << "Numarul de like-uri a fost schimbat";
        }
        if (m == 5)
        {
            cout << "Trailer nou:";
            cin >> trailer;
            out1 << t << " " << gen << " " << nr_likes << " " << trailer;
            cout << "Trailer-ul a fost schimbat";
        }
        out1.close();

    }
    else
        cout << "Filmul pe care doriti sa-l modificati,nu exista!";
}

void Film::Cautare(int option)
{
    vector<Film> aux;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    string gen;
    cout << "Genul este: ";
    cin >> gen;
    int ok = 0;
    int k = 1;
    ifstream in1("filme.txt", ios::in);
    while (in1 >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
    {
        f.titel = titel;
        f.genre = genre;
        f.aparitie_an = aparitie_an;
        f.nr_likes = nr_likes;
        f.trailer = trailer;
        aux.push_back(f);//creating a vect
    }
    for (auto it : aux) /// searching in the film list
    {
        if (gen == it.genre && k == 1) /// first gen
        {
            cout << it.titel << " " << it.genre << " " << it.aparitie_an << " " << it.nr_likes << " " << it.trailer << endl;
            string From = string(it.trailer);
            wstring To(From.begin(), From.end()); // string => wstring
            LPCWSTR Last = To.c_str(); // wstring => LPCWSTR
            LPCWSTR C = TEXT("open");
            ShellExecute(NULL, C, Last, NULL, NULL, SW_SHOWNORMAL); ///accesing browserul
            ok = 1;
            int m;
            do
            {
                
                cout << "1.Continuati / Adaugati" << endl;
                cout << "2.Nu Adaugati / Continuati" << endl;
                cout << "0.Iesiti " << endl;
                cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
                cin >> m;
                //continuare/adaugare
                if (m == 1)
                {
                    addToListaFilme(it);
                    break;
                }
                else
                    //continuing option
                    if (m == 2)
                        break;
                    else
                        if (m == 0)
                        {
                            cout << "Ati iesit din modul cautare";
                            k = 0;
                            break;
                        }
                //Sleep(3000);
                //system("CLS");
            } while (m != 0);
        }
    }
    addToListaFilme2(option);
    if (ok == 0) 
    {
        cout << "Nu s-a gasit film, va atasam lista de filme pentru o noua cautare";
        string topicName = "filme";
        topicName = "notepad \"" + topicName + "\"";  /// deschiderea fisierului txt;

        system(topicName.c_str());
    }
}

// adding in film list

void Film::addToListaFilme(Film it) {
    int ok = 1;
    
    for (auto i : ListaFilme) {
        if (i.titel == it.titel) {
            cout << "\nFilm se afla in Lista!\n";
            ok = 0;
        }
    }
    if (ok == 1) {
        ListaFilme.push_back(it);
        cout << "\nFilm Adaugat cu succes.\n";
    }

}

void Film::addToListaFilme2(int optiune)
{
    /// adding 2 options html / csv
    if (optiune == 1)
    {
        ofstream myfile;
        myfile.open("filme.csv");    //deschidere csv
        myfile << "Lista de filme.\n";
        for (auto i : ListaFilme)
        {
            // scriere in fisier csv
            myfile << i.titel << "," << i.genre << "," << i.aparitie_an << "," << i.nr_likes << "," << i.trailer << "\n";

        }
        myfile.close();
    }
    else
        if (optiune == 2)
        {
            //scrierea in html
            ofstream myfile;
            myfile.open("Watchliste.html"); //deschidere html
            myfile << "<!doctype html>\n";
            myfile << "<html>\n";
            myfile << "<head><title> Watchliste </title></head>\n";
            myfile << "<body>\n";
            myfile << "<table border=1>\n"; ///bordura
            myfile << "<tr>\n";
            myfile << "<td> Titel </td>\n";    ///coloanele
            myfile << "<td> Genre </td>\n";
            myfile << "<td> Jahr </td>\n";
            myfile << "<td> Likes </td>\n";
            myfile << "<td> Trailer link </td>\n";
            myfile << "</tr>\n";
            for (auto it : ListaFilme)
            {
                myfile << "<tr>\n";
                myfile << "<td>" << it.titel << "</td>\n";
                myfile << "<td>" << it.genre << "</td>\n";
                myfile << "<td>" << it.aparitie_an << "</td>\n";
                myfile << "<td>" << it.nr_likes << "</td>\n";
                myfile << "<td><a href =" << it.trailer << ">link</a></td>\n";
                myfile << "</tr>\n";
            }
            myfile << "</table>\n";
            myfile << "</body>\n";
            myfile << "</html>\n";

        }
}
void Film::stergere(int option)
{
    vector<Film> ax;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    ifstream in1("filme.txt", ios::in);
    while (in1 >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
    {
        f.titel = titel;
        f.genre = genre;
        f.aparitie_an = aparitie_an;
        f.nr_likes = nr_likes;
        f.trailer = trailer;
        ax.push_back(f);//creating a vector
    }
    vector<Film> aux;
    vector<Film> aux1;
    int ok = 0;
    string titlu;
    cout << "Dati titlul: ";
    cin >> titlu;
    for (auto it : ListaFilme) 
    {
        if (it.titel == titlu) ///search for the title
        {
            ok = 1;
            cout << "Doriti sa dati un like la aceast film\n";
            cout << "Tasta 1 = Da\n";
            cout << "Tasta 2 = Nu\n";
            cout << "Apasati Tasta = ";
            int n;
            cin >> n;
            if (n == 1) 
            {
                for (const auto& film : ax) /// looping through film list
                    if (film.titel == titlu)
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes + 1; ///modifying the price
                        f.trailer = film.trailer;
                        aux.push_back(f);
                    }
                    else
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes;
                        f.trailer = film.trailer;
                        aux.push_back(f);
                    }
                ax = aux;//e aux in vectoru ax
                ofstream out("filme.txt", ios::out);
                for (const auto& film : aux) /// adaugam in fisier schimbarea
                    out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
                out.close();
                for (const auto& film : ListaFilme)
                    if (film.titel != titlu)   ///deleting the film
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes;
                        f.trailer = film.trailer;
                        aux1.push_back(f);
                    }
                ListaFilme = aux1;
                cout << "Filmul a fost sters cu succes";
            }

            else
                if (n == 2)
                {
                    for (const auto& film : ListaFilme)
                        if (film.titel != titlu)    ///deleing film from lista de Vizionare
                        {
                            f.titel = film.titel;
                            f.genre = film.genre;
                            f.aparitie_an = film.aparitie_an;
                            f.nr_likes = film.nr_likes;
                            f.trailer = film.trailer;
                            aux.push_back(f);//cnew vector withouth the one we are deleting
                        }
                    ListaFilme = aux1;//aux in vectoru v
                    cout << "Filmul a fost sters cu succes";

                }
                else
                    if (n != 1 && n != 2)
                        cout << "Tasta incorecta";
        }


    }
    addToListaFilme2(option);
    if (ok == 0)
        cout << "Nu exista filmul";

}
void Film::Afisare(int optiune)
{/// displaying lista de vizionare
    if (optiune == 1)
    {
        string topicName = "example.csv";
        system(topicName.c_str());  /// afisare lista csv
    }
    else
        if (optiune == 2)
        {
            string topicName = "webex.html"; /// afisare lista html;
            system(topicName.c_str());
        }
}
