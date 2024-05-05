/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
using namespace std;
#include "DVD.h"
#include "Medium.h"
#include "String.h"

DVD::DVD() : Medium("Unbekannter Typ", 0, 0, "Unbekannter Titel"){
	this->dauer = 0;
}

DVD::DVD(String typ, int id) : Medium(typ, id, 0, "Unbekannter Titel"){
	this->dauer = 0;
}

DVD::DVD(String typ, int id, int status) : Medium(typ, id, status, "Unbekannter Titel"){
	this->dauer = 0;
}

DVD::DVD(String typ, int id, int status, String titel) : Medium(typ, id, status, titel){
	this->dauer = 0;
}

DVD::DVD(String typ, int id, int status, String titel, int dauer) : Medium(typ, id, status, titel){
	this->dauer = dauer;
}

/*Getter*/
int DVD::getDauer() const {
    return dauer;
}

void DVD::show() const {
    std::cout << "Typ: " << getTyp() << " | Id: " << getId() << " | Status: " << getStatus() << " | Titel: " << getTitel() << " | Dauer: " << dauer << std::endl;
}

