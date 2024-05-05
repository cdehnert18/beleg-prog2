/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */
#ifndef BUCH_H
#define BUCH_H

#include <iostream>
using namespace std;
#include "String.h"
#include "Medium.h"

class Buch : public Medium{
public:
	/*Konstruktoren*/
    Buch();
	Buch(String typ, int id);
	Buch(String typ, int id, int status);
	Buch(String typ, int id, int status, String titel);
	Buch(String typ, int id, int status, String titel, String autor);
	Buch(String typ, int id, int status, String titel, String autor, int seiten);

	/*Getter*/
	String getAutor() const;
	int getSeiten() const;

	void show() const override;

private:
		String autor;
        int seiten;
};

#endif
