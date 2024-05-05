/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
using namespace std;
#include "Medium.h"
#include "String.h"

/*Konstruktoren*/
Medium::Medium() {
	this->typ = "Unbekannter Typ";
	this->id = 0;
	this->status = 0;
	this->titel = "Unbekannter Titel";
}

Medium::Medium(String typ, int id) {
	this->typ = typ;
	this->id = id;
	this->status = 0;
	this->titel = "Unbekannter Titel";
}

Medium::Medium(String typ, int id, int status) {
	this->typ = typ;
	this->id = id;
	this->status = status;
	this->titel = "Unbekannter Titel";
}

Medium::Medium(String typ, int id, int status, String titel) {
	this->typ = typ;
	this->id = id;
	this->status = status;
	this->titel = titel;
}

/*Getter*/
String Medium::getTyp() const {
	return this->typ;
}

int Medium::getId() const {
	return this->id;
}

int Medium::getStatus() const {
	return this->status;
}

String Medium::getTitel() const {
	return this->titel;
}

/*Setter*/
void Medium::setStatus(int status) {
	this->status = status;
	return;
}

void Medium::show() const {
	cout << "Typ: " << this->typ << " | ID: " << this->id << " | Status: " << this->status << " | Titel: " << this->titel << endl;
	
	return;
}
