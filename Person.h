/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;
#include "String.h"

class Person{
public:
	/*Konstruktoen*/
	Person(int id);
	Person(int id, String vorname, String nachname);

	/*Getter*/
	String getVorname() const ;
	String getNachname() const ;
	int getId() const ;
private:
	String vorname;
	String nachname;
	int id;
};

#endif
