#/bin/bash

clear

g++ Main.cpp String.cpp List.h Node.h Medium.cpp DVD.cpp Buch.cpp Person.cpp -Wall -o Medienverwaltung

if [ $? -ne 0 ]
then
	echo "ERROR"
	echo "g++ Main.cpp String.cpp List.h Node.h Medium.cpp DVD.cpp Buch.cpp Person.cpp -Wall -o Medienverwaltung"
else
	echo "OK"
fi


