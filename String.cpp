/*
 *	Clemens Dehnert
 *	sNr.:	s85492
 *	MN:	53041
 *	SGNr.:	22/041/61
 *	Mail:	clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
#include <cstring>
using namespace std;
#include "String.h"

/*Default-Konstruktor*/
String::String(){
	Len = 0;
	pBuf = new char[1];
	pBuf[0] = '\0';
}

/*Konstruktor*/
String::String(const char* pStr){
	Len = strlen(pStr);
	pBuf = new char[Len+1];
	strcpy(pBuf, pStr);
	pBuf[Len] = '\0';

}

/*Konstruktor*/
String::String(const String& other){
	Len = other.Len;
	pBuf = new char[Len+1];
	strcpy(pBuf, other.pBuf);
	pBuf[Len] = '\0';
}

/*Konstruktor*/
String::String(char C, int n){
	Len = n;
	pBuf = new char[Len+1];
	for(int i = 0; i<n; i++){
		pBuf[i] = C;
	}
	pBuf[Len] = '\0';
}

/*Destruktor*/
String::~String(){
	delete []pBuf;
}

int String::getLen(){
	return this->Len;
}

int String::strcmp(char const* myChar){
	int j = 0;
    while (myChar[j] != '\0') {
        j++;
    }
    if (Len != j) {
        return 1;
    }
    for (int i = 0; i < Len; i++) {
        if (pBuf[i] == myChar[i]) {
            continue;
        } else {
            return 1;
        }
    }
    // Vergleich, ob beide Strings mit Nullterminator enden
    if (pBuf[Len] == '\0' && myChar[Len] == '\0') {
        return 0;
    } else {
        return 1;
    }
}

int String::strcmp(String myString){
	int i = 0;
    while(1){
		if(myString.getLen() == i && Len == i){
			return 0;
		}
		if (pBuf[i] == '\0' && myString.pBuf[i] == '\0') {
            return 0;
        }
		if(pBuf[i] == '\0'){
			return -1;
		}
		if(myString.pBuf[i] == '\0'){
			return 1;
		}
		if(pBuf[i] != myString.pBuf[i]){
			if(pBuf[i] < myString.pBuf[i]){
				return -1;
			}else{
				return 1;
			}
		}
		i++;
	}
}

int String::toInt() const {
	return atoi(pBuf);
}

void String::show(){
	cout << pBuf << endl; 
}

char& String::CIdx(int i){
static char dummy = ' ';
	if(i < Len && i >= 0){
		return pBuf[i];
	}else{
		cerr << "Indexfehler " << i << endl;
		return dummy;
	}
}

/*Operatorenüberladung:	Übernehme von anderem String*/
String& String::operator=(const String& other){
char* tmp;
	tmp = new char(other.Len + 1);
	strcpy(tmp,other.pBuf);
	delete []pBuf;
	Len=other.Len;
	pBuf=tmp;
	
	return *this;
}

/*Operatorenüberladung:	Kreierung String*/
String String::operator+(const String& other)const{
	int l = Len + other.Len + 1;
	char* tmp = new char(l);
	strcpy(tmp, pBuf);
	strcat(tmp, other.pBuf);

	return String(tmp);
}

/*Operatorenüberladung:	Stringerweiterung*/
String& String::operator+=(const String& other){
	int l = Len + other.Len + 1;
	char* tmp = new char(l);
	strcpy(tmp, pBuf);
	strcat(tmp, other.pBuf);
	Len=l;
	delete []pBuf;
	pBuf = tmp;	

	return *this;
}

String& String::operator+=(char c){
	int l = Len + 1;
	char* tmp = new char[l];
	strcpy(tmp, pBuf);
	tmp[l-1] = c; tmp[l] = '\0';
	Len=l;
	delete []pBuf;
	pBuf = tmp;	

	return *this;
}

/*Operatorenüberladung:	Indexüberprüfung*/
char& String::operator[](int i){
static char dummy = ' ';
	if(i < Len && i >= 0){
		return pBuf[i];
	}else{
		cerr << "Indexfehler " << i << endl;
		return dummy;
	}

	return pBuf[i];
}

/*Operatorenüberladung:	Ausgabe*/
ostream& operator<<(ostream& os, const String& other){
	os << other.pBuf; 
	return os;
}

istream& getline(istream& is, String& str) {
        char c;
        str = ""; // leeren String erzeugen

        while (is.get(c) && c != '\n') { // Zeichen für Zeichen lesen
		str += c; // Zeichen an String anhängen
        }

	return is;
}

