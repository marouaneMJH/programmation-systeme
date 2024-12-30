#!/bin/bash


# demande à l'utilisateur de saisir une suite quelconque de mots 
read -p "Entrez une suite de mots: " -a mots # -a: pour sauvegarder les mots dans un tableau

#${#mots[@]} pour afficher le nombre de mots
echo "${#mots[*]} mots ont été saisis." 
