##External/Arduino de RobotEngine
=================================

Ce dossier contient de quoi compiler la bibliothèque Arduino correctement.

## Version
==========

arduino-1.0.5, le code utilisé est sous LGPL.

Actuellement les makefiles sont faits pour les atmegas328p, mais sont mis dans des sous-dossiers atmega328p/, donc il sera possible d'ajouter des makefiles pour d'autres types d'arduino.

##Dépendences
=============

###Présentation
===============

Les dépendances sont:
- binutils-avr
- avr-gcc: le compilateur pour arduino
- avr-libc
- avrdude: permet de mettre le programme sur l'arduino via USB

###Installation
===============

####Ubuntu
==========
sudo apt-get install binutils-avr gcc-avr avr-libc avrdude

Pour plus d'informations, http://gcc.gnu.org/wiki/avr-gcc

##Compilation 
==============

cd build && make

##Les exemples
=======================

Les exemples sont les exemples officiels, disponibles dans external/arduino-1.0.5/examples/.

Dans chaque exemple, il y a un dossier build/ contenant le makefile, et un dossier src/ .

Pour compiler, il suffit d'aller dans le dossier build de l'exemple en question et de taper:
- sudo make compile    # pour compiler le programme
- sudo make upload     # pour installer le programme sur l'arduino
- sudo make            # pour compiler et installer le programme sur l'arduino

