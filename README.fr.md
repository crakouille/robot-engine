Robot Engine
============

! Attention !
=============

Cette bibliothèque dispose de makefiles pour compiler/uploader des programmes sur 
des cartes arduino, à partir de Linux. 

Les programmes sont TOUJOURS uploadés sur /dev/ttyACM0, 
vérifiez donc avant d'utiliser les makefiles que /dev/ttyACM0 correspond bien à votre carte arduino, et pas à un autre périphérique ! (si /dev/ttyACM0 existe alors que la carte arduino n'est pas branchée, alors il faudra trouver le bon tty, et changer les makefile vous même pour les adapter).

Présentation
============

Le but de cette bibliothèque est de fournir une gestion simple et efficace du développement 
de robots, dépendante de linux, mais indépendante des cartes Arduino: les exemples utilisent des cartes Arduino, mais le code n'est pas dans la bibliothèque, juste dans le code des exemples (et dans les dossiers src/Utils et include/Utils afin de ne pas réimplémenter 
certaines classes à chaque projet).

Dans "Robot Engine":
- On définit un "component" comme un effecteur ou un capteur
- On définit un "module" comme un ensemble de "modules" et de "components" 
- Le programme principal du robot est écrit dans un module, qui contient tous les autres 

Codage d'un "component": mise en place sur Arduino (et sur carte mère si elle dispose de pins, comme Raspberry).
Codage d'un "module": mise en place sur Arduino ou carte mère.

Cette bibliothèque permet l'activation des modules du robot en cours d'exécution: gestion du Plug & Play.

Plateformes supportées
======================

PC:
- Linux

Cartes électroniques:
- Arduino:
  - Atmega328p

Quand je disposerai d'autres types de cartes électroniques, j'ajouterai de nouveaux makefiles.

Developpement Arduino
=====================

Il n'est pas obligatoire de développer pour arduino, mais la bibliothèque dispose 
de la lib arduino et d'implémentations dans le dossier "include/Utils" et "src/Utils" pour arduino.

Si vous souhaitez utiliser des cartes arduino pour le développement, 
lisez le paragraphe suivant:

Regardez le dossier external/arduino, il y a un autre fichier README.fr.md qui contient les informations quant à la compilation de la bibliothèque Arduino (le dossier arduino a été allégé pour ne contenir que les sources nécessaires).

Notes :
=======

- L'ouverture du ttyACM0 depuis le programme C++ sur la carte mère provoque le reboot de l'arduino, et il faut attendre 2 secondes avant de pouvoir communiquer en Serial, sinon l'arduino n'est pas prête: c'est l'arduino qui est comme ça.

- Détection du branchement d'un cable usb: utiliser udev

