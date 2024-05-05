/*
 *	    Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */
#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String{
private:  
        char* 	pBuf;
        int	Len;
public:
        /*Konstruktoren*/
        String ();
        String (const char* pStr);
        String (const String& other);		/*Kopierkonstruktor*/
        String (char C, int n);

        /*Destruktor*/
        ~String();				/*Destruktor leer pBuf*/

        /*Getter*/
        int getLen();

        void show();
        int strcmp(String myString);
        int strcmp(char const* myChar);
        int toInt() const;
        char& CIdx(int i); 			//liefert eine Referenz auf das i-te Zeichen

        /*Operatorenüberladung*/
        String& operator=(const String& other);
        String operator+(const String& other)const;
        String& operator+=(const String& other);
        String& operator+=(char c);
        char& operator[](int i);

        friend ostream& operator<<(ostream& os, const String& other);
        friend istream& getline(istream& is, String& str);
};

#endif
