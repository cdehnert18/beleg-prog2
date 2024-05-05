/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
using namespace std;
#include "Buch.h"
#include "Medium.h"
#include "String.h"

/*Konstruktoren*/
Buch::Buch() : Medium("Unbekannter Typ", 0, 0, "Unbekannter Titel"){
	this->autor = "Unbekannter Autor";
	this->seiten = 0;
}

Buch::Buch(String typ, int id) : Medium(typ, id, 0, "Unbekannter Titel"){
	this->autor = "Unbekannter Autor";
	this->seiten = 0;
}

Buch::Buch(String typ, int id, int status) : Medium(typ, id, status, "Unbekannter Titel"){
	this->autor = "Unbekannter Autor";
	this->seiten = 0;
}

Buch::Buch(String typ, int id, int status, String titel) : Medium(typ, id, status, titel){
	this->autor = "Unbekannter Autor";
	this->seiten = 0;
}

Buch::Buch(String typ, int id, int status, String titel, String autor) : Medium(typ, id, status, titel){
	this->autor = autor;
	this->seiten = 0;
}

Buch::Buch(String typ, int id, int status, String titel, String autor, int seiten) : Medium(typ, id, status, titel){
	this->autor = autor;
	this->seiten = seiten;
}

/*Getter*/
String Buch::getAutor() const {
    return this->autor;
}

int Buch::getSeiten() const {
    return this->seiten;
}

void Buch::show() const {
    std::cout << "Typ: " << getTyp() << " | Id: " << getId() << " | Status: " << getStatus() << " | Titel: " << getTitel() << " | Autor: " << autor << " | Seiten: " << seiten << std::endl;
}

