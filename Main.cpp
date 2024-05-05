/*
 *      Clemens Dehnert
 *      sNr.:   s85492
 *      MN:     53041
 *      SGNr.:  22/041/61
 *      Mail:   clemens.dehnert@stud.htw-dresden.de
 * */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;
#include "Node.h"
#include "List.h"
#include "String.h"
#include "Medium.h"
#include "DVD.h"
#include "Buch.h"
#include "Person.h"

void load();
void save();
int mainMenu();
int medienVerwaltung();
int personenVerwaltung();
int ausleihe();
int rueckgabe();
int checkIDMedien(int id);
int checkIDPersonen(int id);
void sortMedien(int art);
void sortPersonen(int art);

List<Medium> medienListe;
List<Person> personenListe;

int main(int argc, char* argv[]){
	int action = 0;

	load();
	do{
		action = mainMenu();
		if(action == 1){
			system("clear");
			medienVerwaltung();
		}
		if(action == 2){
			system("clear");
			personenVerwaltung();
		}
		if(action == 3){
			system("clear");
			ausleihe();
		}
		if(action == 4){
			system("clear");
			rueckgabe();
		}
	}while(action != 0);
	save();

	return 0;
}

/*Stückweises Laden aus Datei & nach Typ zuordnen*/
void load(){

	ifstream myFile("Medium.txt");

    if (!myFile) {
        cerr << "Fehler beim Öffnen der Datei!" << endl;
        return;
    }

	string line;
    while (getline(myFile, line)){

		String typ = "";
		String idS = "";
		int id;
		String statusS = "";
		int status;
		String titel = "";
		int dauer;
		String dauerS = "";
		String autor = "";
		int seiten;
		String seitenS = "";
		String titelM = "";

        int i = 0; int j = 0;
		while(line[i] != ';'){		//Typ
			i++;
		}
		for(int b = 0; b < i; b++){
			typ += line[b];
		}
		i++;

		j = i;
		while(line[i] != ';'){		//Id
			i++;
		}
		for(int b = j; b < i; b++){
			idS += line[b];
		}
		id = idS.toInt();
		i++;

		j = i;
		while(line[i] != ';'){		//Status
			i++;
		}
		for(int b = j; b < i; b++){
			statusS += line[b];
		}
		status = statusS.toInt();
		i++;

		if(typ.strcmp("DVD") == 0){
			j = i;
			while(line[i] != ';'){		//Titel
				i++;
			}
			for(int b = j; b < i; b++){
				titel += line[b];
			}
			i++;

			j = i;
			while(line[i] != ';'){		//Dauer
				i++;
			}
			for(int b = j; b < i; b++){
				dauerS += line[b];
			}
			dauer = dauerS.toInt();
			i++;

			DVD* myDVD = new DVD(typ, id, status, titel, dauer);
			medienListe.addToList(myDVD);
			continue;
		}
		if(typ.strcmp("Buch") == 0){
			j = i;
			while(line[i] != ';'){		//Titel
				i++;
			}
			for(int b = j; b < i; b++){
				titel += line[b];
			}
			i++;

			j = i;
			while(line[i] != ';'){		//Autor
				i++;
			}
			for(int b = j; b < i; b++){
				autor += line[b];
			}
			i++;

			j = i;
			while(line[i] != ';'){		//Seiten
				i++;
			}
			for(int b = j; b < i; b++){
				seitenS += line[b];
				//cout << seitenS[b] << endl;
			}
			seiten = seitenS.toInt();
			i++;

			Buch* myBuch = new Buch(typ, id, status, titel, autor, seiten);
			medienListe.addToList(myBuch);
			continue;
		}

		j = i;
		while(line[i] != ';'){		//Titel
			i++;
		}
		for(int b = j; b < i; b++){
			titelM += line[b];
		}
		Medium* pMedium = new Medium(typ, id, status, titelM);
		medienListe.addToList(pMedium);

    }

	myFile.close();

	ifstream myFilePers("Personen.txt");

    if (!myFilePers) {
        cerr << "Fehler beim Öffnen der Datei!" << endl;
        return;
    }

    while (getline(myFilePers, line)){

		String idS = "";
		int id;
		String vornameS = "";
		String nachnameS = "";

        int i = 0; int j = 0;
		while(line[i] != ';'){		//Id
			i++;
		}
		for(int b = j; b < i; b++){
			idS += line[b];
		}
		id = idS.toInt();
		i++;

		j = i;
		while(line[i] != ';'){		//Titel
			i++;
		}
		for(int b = j; b < i; b++){
			vornameS += line[b];
		}
		i++;

		j = i;
		while(line[i] != ';'){		//Titel
			i++;
		}
		for(int b = j; b < i; b++){
			nachnameS += line[b];
		}
		i++;

		Person* myPerson = new Person(id, vornameS, nachnameS);
		personenListe.addToList(myPerson);
    }

	myFilePers.close();

	return;
}

void save(){
	ofstream myfile("Medium.txt");
	if (myfile.is_open()) {
		for(int i = 0; i < medienListe.getSize(); i++){
			Medium* pMedium = medienListe.getFromList(i);
			String typ = pMedium->getTyp();
			myfile << pMedium->getTyp() << ";";
			myfile << pMedium->getId() << ";";
			myfile << pMedium->getStatus() << ";";
			myfile << pMedium->getTitel() << ";";
			if(typ.strcmp("DVD") == 0){
				DVD* myDVD = dynamic_cast<DVD*>((DVD*)pMedium);
				myfile << myDVD->getDauer() << ";" << endl;
			}
			if(typ.strcmp("Buch") == 0){
				Buch* myBuch = dynamic_cast<Buch*>((Buch*)pMedium);
				myfile << myBuch->getAutor() << ";";
				myfile << myBuch->getSeiten() << ";" << endl;
			}

		}
		myfile.close();
		cout << "Medien: Data saved to file." << endl;
	}else{
		cout << "Medien: Unable to open file." << endl;
	}

	ofstream myfilePers("Personen.txt");
	if (myfilePers.is_open()) {
		for(int i = 0; i < personenListe.getSize(); i++){
			Person* pPerson = personenListe.getFromList(i);
			myfilePers << pPerson->getId() << ";";
			myfilePers << pPerson->getVorname() << ";";
			myfilePers<< pPerson->getNachname() << ";" << endl;
		}
		myfilePers.close();
		cout << "Personen: Data saved to file." << endl;
	}else{
		cout << "Personen: Unable to open file." << endl;
	}

	return;
}

int mainMenu(){
int action = 0;

	cout << "~ Hauptmenü ~" << endl;
	cout << "Medienverwaltung: 1 || Personenverwaltung: 2 || Ausleihe: 3 || Rückgabe: 4 || Exit: 0" << endl;

	cin >> action;

	return action;
}

int medienVerwaltung(){
int subaction = 0;

	system("clear");
	cout << "~ Medienverwaltung ~" << endl;
	do{
	cout << "Medium hinzufügen: 1 || Medium anzeigen: 2 || alle Medien anzeigen: 3 || Medium löschen: 4 || Medium suchen: 5 || Exit: 0" << endl;
	cin >> subaction;

	/*Hinzufügen*/
	if(subaction == 1){
		char pTyp[32+1] = "";
		String typ; int id = 0; int status; String titel; int dauer; String autor; int seiten;

		cout << "~ Medium hinzufügen ~" << endl;
		cout << "Typ: ";

		cin.ignore();
		cin.getline(pTyp, 32+1);
		typ = pTyp;

		cout << "Id: ";
		cin >> id;
		if(checkIDMedien(id) == 1){
			continue;
		}

		cout << "Status: ";
		cin >> status;

		cout << "Titel: ";
		cin.ignore();
		cin.getline(pTyp, 32+1);
		titel = pTyp;

		if(typ.strcmp("DVD") == 0){
			cout << "Dauer: ";
			cin >> dauer;

			DVD* myDVD = new DVD(typ, id, status, titel, dauer);
        		medienListe.addToList(myDVD);
		}

		if(typ.strcmp("Buch") == 0){
			cout << "Autor: ";
			cin.getline(pTyp, 32+1);
			autor = pTyp;
			cout << "Seitenanzahl: ";
			cin >> seiten;
			Buch* myBuch = new Buch(typ, id, status, titel, autor, seiten);
        		medienListe.addToList(myBuch);
		}

		if(typ.strcmp("Buch") == 1 && typ.strcmp("DVD") == 1){
			Medium* myMedium = new Medium(typ, id, status, titel);
			medienListe.addToList(myMedium);
		}
	}

	/*einzelnes Medium anzeigen*/
	if(subaction == 2){
		int index = 0;
		cout << "Index: ";
		cin >> index;

		Medium* pMedium = medienListe.getFromList(index);
		if(pMedium == NULL){
			continue;
		}
		String typ = pMedium->getTyp();

		cout << "Typ: " << typ << " ID: " << pMedium->getId() << " Status: " << pMedium->getStatus() << " Titel: " << pMedium->getTitel();

		if(typ.strcmp("DVD") == 0){
			DVD* pDVD = dynamic_cast<DVD*>((DVD*)pMedium);
			cout << " Dauer: " << pDVD->getDauer();
		}
		if(typ.strcmp("Buch") == 0){
			Buch* pBuch = dynamic_cast<Buch*>((Buch*)pMedium);
			cout << " Autor: " << pBuch->getAutor() << " Seiten: " << pBuch->getSeiten();
		}
		cout << endl;
	}

	/*alle Medien anzeigen*/
	if(subaction == 3){
		int sort;
		cout << "Sortiert Typ: 1 || Sortiert Titel: 2 || Unsortiert: sonstig" << endl;
		cin >> sort;
		if(sort == 1 || sort == 2){
			sortMedien(sort);
		}
		for(int i = 0; i < medienListe.getSize(); i++){
			Medium* pMedium = medienListe.getFromList(i);
			String typ = pMedium->getTyp();

			cout << "Typ: " << typ << " ID: " << pMedium->getId() << " Status: " << pMedium->getStatus() << " Titel: " << pMedium->getTitel();

			if(typ.strcmp("DVD") == 0){
				DVD* pDVD = dynamic_cast<DVD*>((DVD*)pMedium);
				cout << " Dauer: " << pDVD->getDauer();
			}
			if(typ.strcmp("Buch") == 0){
				Buch* pBuch = dynamic_cast<Buch*>((Buch*)pMedium);
				cout << " Autor: " << pBuch->getAutor() << " Seiten: " << pBuch->getSeiten();
			}
			cout << endl;
		}
	}

	/*Medium löschen*/
	if(subaction == 4){
		int index = 0;
                cout << "Index: ";
                cin >> index;

                if(medienListe.getFromList(index) == NULL){
                        continue;
                }
		medienListe.removeFromList(index);
	}

	/*Medium suchen*/
	if(subaction == 5){
		string line;
		String sline;
		Medium* pMedium;
		cout << "Name des Mediums: " << endl;
		cin.ignore();
		getline(cin, line);
		int i = 0;
		char c;
		do{
			c = line[i];
			sline += line[i];
			i++;
		}while(c != '\0');
		for(int i = 0; i < medienListe.getSize(); i++){
			pMedium = medienListe.getFromList(i);
			if(pMedium->getTitel().strcmp(sline) == 0){
				cout << "Treffer: " << sline << " ID: " << pMedium->getId() << endl;
			}
		}
	}

	/*Medienverwaltung verlassen*/
	}while(subaction != 0);

	return 0;
}

int personenVerwaltung(){
int subaction = 0;
	system("clear");
	cout << "~ Personenverwaltung ~" << endl;
	do{
		cout << "Person hinzufügen: 1 || Person anzeigen: 2 || alle Personen anzeigen: 3 || Person löschen: 4 || Person suchen: 5 || Exit: 0" << endl;
		cin >> subaction;

		/*Hinzufügen*/
		if(subaction == 1){
			int id = 0;
			char vorname[32+1] = "";
			char nachname[32+1] = "";

			cout << "~ Person hinzufügen ~" << endl;
			cout << "Id: ";

			cin >> id;
			if(checkIDPersonen(id) == 1){
				continue;
			}

			cout << "Vorname: ";
			cin.ignore();
			cin.getline(vorname, 32+1);
			String vornameS = vorname;

			cout << "Nachname: ";
			cin.getline(nachname, 32+1);
			String nachnameS = nachname;

			Person* myPerson = new Person(id, vornameS, nachnameS);
			personenListe.addToList(myPerson);
		}

		/*eine Person anzeigen*/
		if(subaction == 2){
			int index = 0;
			cout << "Index: ";
			cin >> index;

			if(personenListe.getFromList(index) == NULL){
				continue;
			}
			Person* pPerson = personenListe.getFromList(index);
			cout << "ID: " << pPerson->getId() << " Vorname: " << pPerson->getVorname() << " Nachname: " << pPerson->getNachname() << endl;
		}

		/*alle Personen anzeigen*/
		if(subaction == 3){
		int sort;
		cout << "Sortiert Vorname: 1 || Sortiert Nachname: 2 || Unsortiert: sonstig" << endl;
		cin >> sort;
		if(sort == 1 || sort == 2){
			sortPersonen(sort);
		}
			for(int i = 0; i < personenListe.getSize(); i++){
				Person* pPerson = personenListe.getFromList(i);
				cout << "ID: " << pPerson->getId() << " Vorname: " << pPerson->getVorname() << " Nachname: " << pPerson->getNachname() << endl;
			}
		}

		/*Person löschen*/
		if(subaction == 4){
		int index = 0;
                cout << "Index: ";
                cin >> index;

                if(personenListe.getFromList(index) == NULL){
                        continue;
                }
			personenListe.removeFromList(index);
		}

		/*Person suchen*/
		if(subaction == 5){
			string line;
			String sline;
			Person* pPerson;
			cout << "Name der Person: " << endl;
			cin.ignore();
			getline(cin, line);
			int i = 0;
			char c;
			do{
				c = line[i];
				sline += line[i];
				i++;
			}while(c != '\0');
			for(int i = 0; i < personenListe.getSize(); i++){
				pPerson = personenListe.getFromList(i);
				if(pPerson->getVorname().strcmp(sline) == 0 || pPerson->getNachname().strcmp(sline) == 0){
					cout << "Treffer: " << sline << " ID: " << pPerson->getId() << endl;
				}
			}
		}

	}while(subaction != 0);

	return 0;
}

int ausleihe(){
	int pId = 0;	bool pA = false;
	int mId = 0;	bool mA = false;

	system("clear");
	cout << "~ Ausleihe ~" << endl;
	cout << "PersonenID: ";
	cin >> pId;
	cout << endl;
	cout << "MedienID: " << endl;
	cin >> mId;

	for(int i = 0; i < personenListe.getSize(); i++){
		Person* pPerson = personenListe.getFromList(i);
		if(pPerson->getId() == pId){
			cout << "Person gefunden" << endl;
			pA = true;
			break;
		}

	}

	Medium* pMedium = NULL;
	for(int i = 0; i < medienListe.getSize(); i++){
		pMedium = medienListe.getFromList(i);
		if(pMedium->getId() == mId){
			cout << "Medium gefunden" << endl;
			mA = true;
			break;
		}
	}

	if(pA == true && mA == true && pMedium->getStatus() == 0){
		pMedium->setStatus(pId);
	}else{
		cout << "Aktion nicht durchführbar, da Angaben falsch waren" << endl;
	}

	return 0;
}

int rueckgabe(){
	int pId = 0;	bool pA = false;
	int mId = 0;	bool mA = false;

	system("clear");
	cout << "~ Rückgabe ~" << endl;
	cout << "PersonenID: ";
	cin >> pId;
	cout << endl;
	cout << "MedienID: " << endl;
	cin >> mId;

	for(int i = 0; i < personenListe.getSize(); i++){
		Person* pPerson = personenListe.getFromList(i);
		if(pPerson->getId() == pId){
			cout << "Person gefunden" << endl;
			pA = true;
			break;
		}
	}

	Medium* pMedium;
	for(int i = 0; i < medienListe.getSize(); i++){
		pMedium = medienListe.getFromList(i);
		if(pMedium->getId() == mId){
			cout << "Medium gefunden" << endl;
			mA = true;
			break;
		}
	}

	if(pA == true && mA == true && pMedium->getStatus() == pId){
		pMedium->setStatus(0);
	}else{
		cout << "Aktion nicht durchführbar, da Angaben falsch waren" << endl;
	}

	return 0;
}

int checkIDMedien(int id){
	for(int i = 0; i < medienListe.getSize(); i++){
		Medium* pMedium = medienListe.getFromList(i);
		int tempID = pMedium->getId();
		if(id == tempID){
			cout << "ID bereits vergeben." << endl;
			return 1;
		}
	}
	return 0;
}

int checkIDPersonen(int id){
	if(id == 0){
		cout << "ID darf nicht 0 sein." << endl;
		return 1;
	}
	for(int i = 0; i < personenListe.getSize(); i++){
		Person* pPerson = personenListe.getFromList(i);
		int tempID = pPerson->getId();
		if(id == tempID){
			cout << "ID bereits vergeben." << endl;
			return 1;
		}
	}
	return 0;
}

void sortMedien(int art){
	if(art == 1){
		int i, j;
		bool swapped;
		for (i = 0; i < medienListe.getSize() - 1; i++){
			swapped = false;
			for (j = 0; j < medienListe.getSize() - i - 1; j++) {
				String Typ1 = medienListe.getFromList(j)->getTyp();
				String Typ2 = medienListe.getFromList(j+1)->getTyp();
				if (Typ1.strcmp(Typ2) == 1) {
					medienListe.swapWithNext(j);
					swapped = true;
				}
			}
			if (swapped == false){
				break;
			}
		}
	}

	if(art == 2){
		int i, j;
		bool swapped;
		for (i = 0; i < medienListe.getSize() - 1; i++){
			swapped = false;
			for (j = 0; j < medienListe.getSize() - i - 1; j++) {
				String Typ1 = medienListe.getFromList(j)->getTitel();
				String Typ2 = medienListe.getFromList(j+1)->getTitel();
				if (Typ1.strcmp(Typ2) == 1) {
					medienListe.swapWithNext(j);
					swapped = true;
				}
			}
			if (swapped == false){
				break;
			}
		}
	}
}

void sortPersonen(int art){
	if(art == 1){
		int i, j;
		bool swapped;
		for (i = 0; i < personenListe.getSize() - 1; i++){
			swapped = false;
			for (j = 0; j < personenListe.getSize() - i - 1; j++) {
				String Typ1 = personenListe.getFromList(j)->getVorname();
				String Typ2 =personenListe.getFromList(j+1)->getVorname();
				if (Typ1.strcmp(Typ2) == 1) {
					personenListe.swapWithNext(j);
					swapped = true;
				}
			}
			if (swapped == false){
				break;
			}
		}
	}

	if(art == 2){
		int i, j;
		bool swapped;
		for (i = 0; i < personenListe.getSize() - 1; i++){
			swapped = false;
			for (j = 0; j < personenListe.getSize() - i - 1; j++) {
				String Typ1 = personenListe.getFromList(j)->getNachname();
				String Typ2 = personenListe.getFromList(j+1)->getNachname();
				if (Typ1.strcmp(Typ2) == 1) {
					personenListe.swapWithNext(j);
					swapped = true;
				}
			}
			if (swapped == false){
				break;
			}
		}
	}
}
