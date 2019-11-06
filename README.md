# Groupe de courta_f & habi_a
#
## Nécessité

#### _Afin de faire fonctionner notre programme, nous avons besoin de :_

- **Build-essential**
- **Make**

## Sujet 

AbstractVM est une machine à pile qui permet d'évaluer des expressions arithmétiques simples. Ces expressions sont fournies à la machine par le biais de programmes écrits dans un langage s'apparentant à l'assembleur.

## Les Instructions

| Instruction          |  Description                                                                       |
| -------------------- | ---------------------------------------------------------------------------------- |
| push "Value"         | Empile la valeur "Value"                                                           |
| pop                  | Dépile une valeur                                                                  |
| add                  | Dépile deux valeurs, calcule leur somme, et empile le résultat                     |
| sub                  | Dépile deux valeurs a et b, calcule la différence b - a, et empile le résultat     |
| mul                  | Dépile deux valeurs, calcule leur produit, et empile le résultat                   |
| div                  | Dépile deux valeurs a et b, calcule le quotient b / a, et empile le résultat       |
| mod                  | Dépile deux valeurs a et b, calcule le modulo b % a, et empile le résultat         |
| assert "Value"       | Vérifie que la valeur située en haut de la pile est égale à la valeur "Value"      |
| dump                 | Affiche le contenu de la pile, du haut vers le bas, en séparant chaque valeur par un retour à la ligne |
| print                | Vérifie que la valeur située en haut de la pile est bien de type int8, et affiche le code ASCII correspondant sur la sortie standard |
| exit                 | Termine l'exécution du programme en cours |

## Mise en route

- ***make***
- ***export LD_LIBRARY_PATH=.***
- ***./abstractvm file.avm***

