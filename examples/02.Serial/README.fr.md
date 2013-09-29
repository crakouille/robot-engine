02.Serial
=========

Voici des exemples de programmes avec une seule carte arduino et une carte mère.

! Attention !
=============

Attention, vérifiez bien que le tty nommé ttyACM0 correspond bien à votre carte arduino avant d'utiliser les makefiles !

Compilation
===========

Aller dans le dossier "arduino/build/atmega328p" d'un exemple que vous souhaitez tester, 
et tapez la commande `sudo make`

Ceci compilera et uploadera le programme sur l'arduino.

Exécution
=========

Une fois le programme pour arduino uploadé, allez dans le dossier "linux/build", 
exécutez `make` puis exécutez le programme compilé (à côté du makefile).

La carte arduino sera rebootée lors de l'activation de la connection Serial, et il lui faudra 
2 secondes avant de pouvoir dialoguer en Serial (pb des cartes Arduino): n'oubliez pas de mettre un "sleep(2);" au début de vos programmes.

