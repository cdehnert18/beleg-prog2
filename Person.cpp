/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
using namespace std;
#include "String.h"
#include "Person.h"

/*Konstruktoren*/
Person::Person(int id){
	this->id = id;
	this->vorname = "Max";
	this->nachname = "Mustermann";
}

Person::Person(int id, String vorname, String nachname){
	this->id = id;
	this->vorname = vorname;
	this->nachname = nachname;
}

/*Getter*/
String Person::getVorname() const {

	return this->vorname;
}

String Person::getNachname() const {
	
	return this->nachname;
}

int Person::getId() const {

	return this->id;
}
