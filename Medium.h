/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */
#ifndef MEDIUM_H
#define MEDIUM_H

#include <iostream>
using namespace std;
#include "String.h"

class Medium{
public:
	/*Konstruktoren*/
	Medium();
	Medium(String typ, int id);
	Medium(String typ, int id, int status);
	Medium(String typ, int id, int status, String titel);

	/*Getter*/
	String getTyp() const ;
	int getId() const ;
	int getStatus() const ;
	String getTitel() const ;

	/*Setter*/
	void setStatus(int status);
	
	virtual void show() const;
private:
	String typ;
	int id;
	int status;
	String titel;
};

#endif
