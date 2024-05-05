/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */
#ifndef DVD_H
#define DVD_H

#include <iostream>
using namespace std;
#include "String.h"
#include "Medium.h"

class DVD : public Medium{
public:
	/*Konstruktoren*/
	DVD();
    DVD(String typ, int id);
	DVD(String typ, int id, int status);
	DVD(String typ, int id, int status, String titel);
	DVD(String typ, int id, int status, String titel, int dauer);
        
	/*Getter*/
	int getDauer() const;

	void show() const override;

private:
        int dauer;
};

#endif
